// (a) 2n is O(n)
// 2n <= 2n
// c = 2, n0 = 0

// (b) 100n+50 is O(n)
//  n = 1の時、　150 <= 150を成り立たせればいい
// 100n+50 <= 150n
// c = 150, n0 = 1

// (c) n^2 + 3n−5 is O(n^2)
//  ここのコツは一個ずつ比べていく、字数に関しても1番次数が高いのに揃えるのがいい
// n^2 <= n^2
// 3n <= 3n^2
// -5 < 0 
// n^2 + 3n + 5 <= n^2 + 3n^2
// n^2 + 3n + 5 <= 4n^2
// c = 4, n0 = 1 -> n^2 + 3n -5 is O(n^2)

// (d) n^2 is NOT O(n)
// proof by contradiction
// Assume for contradiction that n^2 is O(n)
// Then by the difinition of Big-o, there exist constant c > 0 and n0 > 1 such that
// n^2 < cn for all n >= n0
// since n > 0, divide both side by n:
// n <= c
// However, n can arbitrarily large, while c is fixed constant.
// choose n > c. then n <= c is false, which is contradiction.
// Therefore, n^2 is not O(n)

//(e) n^2 is O(n^3)
// n >= 1
// n^2 <= n^3
// c = 1, n0 = 1 -> n^2 is O(n^3)

//(f) polynomial of degree k is O(n^k)
// Let p(n)= a^k​n^k + ak − 1 ​n^k − 1 +⋯+ a1​n + a0​
// be a polynomial of degree k.
// For n >= 1, we have n^i <= n^k
// for every 0≤i≤k. Therefore, there exists a constant
// C = ∣ak​∣ + ∣ak−1​∣ +⋯+ ∣a0​∣
// such that p(n) <= Cnk
// for all n≥1. Thus, by the definition of Big-O,
// p(n) is O(n^k).

// (g) log2(n^3)is O(n)
// we have log2(n^3) = 3log2n
// logn < n
// 3log2n <= 3n^2
// --> log2(n^3) is O(n)

//(h) n^2 + nlogn + 1 is O(n^2)
// n^2 <= n^2
// logn <= n --> nlogn <= n^2
// 1 < n^2
// ---> n^2 + nlogn + 1 <= n^2 + n^2 + n^2 = 3n^2, then n^2 + nlogn + 1 is O(n^2)

//(i) an^k is O(n^k)
// an^k <= cn^k
// when a = c
// an^k <= an^k
// --> an^k is o(n^k)

// (j) an^k is NOT O(n^k−1)
// Assume for contradiction that an^k is O(n^k-1)
// Then there exist constants c>0 and n0 >= 1 such that
// an^k <= cn^k − 1 for all n >= n0
// Since n>0, divide both sides by n^k−1: ---> an < c
// However, a>0 is fixed and n can be arbitrarily large, so an can exceed any fixed constant c.
// This is a contradiction.
// Therefore, an^k is NOT O(n^k-1)