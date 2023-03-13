#include "map.hpp"
#include <iostream>
#include "rbt.hpp"

// int main()
// {
//   ft::map<std::string, int> map1;
//   // map1["something"] = 69;
//   // map1["anything"] = 199;
//   // map1["that thing"] = 50;
//   // std::cout << "map1 = " << map1;
 
// //   // (4) Range constructor
// //   fpos_t::map<std::string, int> iter(map1.find("anything"), map1.end());
// //   std::cout << "\niter = " << iter;
// //   std::cout << "map1 = " << map1;
 
//   // (6) Copy constructor
// //   std::map<std::string, int> copied(map1);
// //   std::cout << "\ncopied = " << copied;
// //   std::cout << "map1 = " << map1;

 
// //   std::cout << "\nCustom Key class option 1:\n";
// //   // Use a comparison struct
// //   std::map<Point, double, PointCmp> mag = {
// //       { {5, -12}, 13 },
// //       { {3, 4},   5 },
// //       { {-8, -15}, 17 }
// //   };
 
// //   for(auto p : mag)
// //       std::cout << "The magnitude of (" << p.first.x
// //                 << ", " << p.first.y << ") is "
// //                 << p.second << '\n';
 
// //   std::cout << "\nCustom Key class option 2:\n";
// //   // Use a comparison lambda
// //   // This lambda sorts points according to their magnitudes, where note that
// //   //  these magnitudes are taken from the local variable mag
// //   auto cmpLambda = [&mag](const Point &lhs, const Point &rhs) {
// //       return mag[lhs] < mag[rhs];
// //   };
// //   // You could also use a lambda that is not dependent on local variables, like this:
// //   // auto cmpLambda = [](const Point &lhs, const Point &rhs) { return lhs.y < rhs.y; };
// //   std::map<Point, double, decltype(cmpLambda)> magy(cmpLambda);
 
// //   // Various ways of inserting elements:
// //   magy.insert(std::pair<Point, double>({5, -12}, 13));
// //   magy.insert({ {3, 4}, 5});
// //   magy.insert({Point{-8.0, -15.0}, 17});
 
// //   for(auto p : magy)
// //       std::cout << "The magnitude of (" << p.first.x
// //                 << ", " << p.first.y << ") is "
// //                 << p.second << '\n';
// }



int main() 
{
  ft::map<int, int> bst;
//  bst.real_print(bst.getroot(), 0, bst);

   bst.insert(ft::make_pair(55, 55));
   bst.insert(ft::make_pair(42, 42));
   bst.insert(ft::make_pair(10, 10));
   bst.insert(ft::make_pair(12, 12));
   bst.insert(ft::make_pair(258, 258));
   bst.insert(ft::make_pair(150, 150));
   bst.insert(ft::make_pair(30, 30));
   //bst.insert(ft::make_pair(0, 0));
   bst.insert(ft::make_pair(9, 9));
//   bst.insert(40);
//   bst.insert(65);
//   bst.insert(60);
//   bst.insert(75);
//   bst.insert(57);
  //  bst.insert(5);
  //  bst.insert(344);
  //  bst.insert(23);


//    bst._rbtree.printTree();
// //   //bst.real_print(bst.getroot(), 0, bst);
// //   std::cout << std::endl;
// //   std::cout << std::endl;
   std::cout << "feiofeoi" << std::endl;

//    bst._rbtree.deleteNodeHelper(bst._rbtree.getroot(), 10);
// //   std::cout << std::endl;
//    bst._rbtree.printTree();

  ft::map<int,int>::iterator it = bst._rbtree.begin(); 
  for (it = bst._rbtree.begin(); it != bst._rbtree.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

   std::cout << "feiofeoi" << std::endl;

  // bst.real_print(bst.getroot(), 0, bst);

}