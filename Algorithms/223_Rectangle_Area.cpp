class Solution {
  public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long area_1 = (C - A) * (D - B);
        long area_2 = (G - E) * (H - F);

        long I = (C < G) ? C : G;
        long J = (E > A) ? E : A;
        long K = (H < D) ? H : D;
        long L = (B > F) ? B : F;

        if (I - J > 0 && K - L > 0) {
            return area_1 + area_2 - (I - J) * (K - L);
        } else {
            return area_1 + area_2;
        }
    }
};
