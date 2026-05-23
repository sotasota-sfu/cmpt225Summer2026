// What is the definition of big-o

// f(n) = O(g(n))
// if there is a real constant c > 0 and an integer constant n0 >= 1 such that 
//.        f(n) < cg(n), for n >= n0;

// ex) 3n + 5 is O(n) を示したいなら
// 3n + 5 <= cn になるようなになるようなcを探す
// c = 4とすると 3n + 5 <= 4n
// これは n <= 5の時に成り立つ
// c = 4
// n0 = 5 これで成り立つので
// 3n + 5 is O(n)になる　