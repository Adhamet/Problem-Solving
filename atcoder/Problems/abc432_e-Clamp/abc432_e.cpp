#include <bits/stdc++.h>

using i64 = long long;
#define el '\n'

constexpr int VALMAX = 5e5+2;
constexpr int TREE_SIZE = 4 * (VALMAX + 5);
i64 treeSm[TREE_SIZE];
i64 treeCnt[TREE_SIZE];

struct SegTreeSum {
      i64 *tree;
      SegTreeSum(i64 *ptr) { tree = ptr; };

      void update(int v, int tl, int tr, int pos, i64 delta) {
            if (tl == tr) tree[v] += delta;
            else {
                  int tm = (tl + tr) >> 1;
                  if (pos <= tm) update(v<<1, tl, tm, pos, delta);
                  else update(v<<1|1, tm+1, tr, pos, delta);
                  tree[v] = tree[v<<1] + tree[v<<1|1];
            }
      }

      i64 query(int v, int tl, int tr, int l, int r) {
            if (l > r || tr < l || tl > r) return 0;
            if (tl >= l && tr <= r) return tree[v];
            int tm = (tl + tr) >> 1;
            i64 lft = query(v<<1, tl, tm, l, std::min(r, tm)); // go left
            i64 rht = query(v<<1|1, tm+1, tr, std::max(l, tm+1), r); // go right
            return lft + rht;
      }
};


int main() {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);

      int n, q;
      std::cin >> n >> q;
      i64 a[n+1];
      SegTreeSum stSm(treeSm), stCnt(treeCnt);
      for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
            stSm.update(1, 0, VALMAX, a[i], a[i]);
            stCnt.update(1, 0, VALMAX, a[i], 1);
      }

      while (q--) {
            int type;
            std::cin >> type;

            if (type == 1) {
                  int idx;
                  i64 val;
                  std::cin >> idx >> val;
                  stSm.update(1, 0, VALMAX, a[idx], -a[idx]);
                  stCnt.update(1, 0, VALMAX, a[idx], -1);
                  a[idx] = val;
                  stSm.update(1, 0, VALMAX, a[idx], a[idx]);
                  stCnt.update(1, 0, VALMAX, a[idx], 1);
            } else {
                  i64 l, r;   std::cin >> l >> r;
                  if (l >= r) std::cout << l * n << '\n';
                  else {
                        i64 a = stCnt.query(1, 0, VALMAX, 0, l-1);
                        i64 b = stSm.query(1, 0, VALMAX, l, r);
                        i64 c = stCnt.query(1, 0, VALMAX, r+1, VALMAX);
                        std::cout << a * l + b + c * r << '\n';
                  }
            }
      }

      return 0;
}

