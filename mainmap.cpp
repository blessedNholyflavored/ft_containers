#include "map.hpp"
#include <iostream>
#include <iomanip>
#include "rbt.hpp"



#define RED     "\033[31m"      
#define BOLDGREEN   "\033[1m\033[32m"      
#define YELLOW  "\033[33m"      
#define BOLDWHITE   "\033[1m\033[37m"
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define RESET   "\033[0m"
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */


#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

int	main(void)
{
    std::cout << YELLOW << "test de begin" << std::endl;
	NAMESPACE::map<int, int> test;
	test.insert(NAMESPACE::make_pair(5, 8));
	test.insert(NAMESPACE::make_pair(1, 3));
	test.insert(NAMESPACE::make_pair(7, 10));
	test.insert(NAMESPACE::make_pair(3, 9));
	test.insert(NAMESPACE::make_pair(4, 11));
	test.insert(NAMESPACE::make_pair(54, 110));

	 NAMESPACE::map<int, int>::iterator it = test.begin();
    for (it = test.begin(); it != test.end(); ++it)
        std::cout << BOLDWHITE << " "  << (it->first) ;
    std::cout<< std::endl;
    std::cout<< std::endl;

	std::cout << YELLOW << "test de end" << std::endl;
    std::cout << BOLDWHITE << "end : " << test.end()->first << std::endl;
    std::cout<< std::endl;

    std::cout << YELLOW << "test de empty et de clear" << std::endl;
    std::cout << BOLDWHITE << "is copy container empty ? " << std::endl;
	test.empty() ? std::cout << BOLDGREEN << "yes!!!!🦆 \n" : std::cout << RED <<"noooo🦖 \n";
	std::cout << BOLDBLACK << "copy containers size = " << test.size() << std::endl;
	std::cout << "\n";
	std::cout << BOLDBLACK << "on clear !!!!!!!!!!!!!\n";
	test.clear();
	std::cout << "\n";
    std::cout << BOLDWHITE << "is copy container empty ? " << std::endl;
	test.empty() ? std::cout <<BOLDGREEN <<  "🐉yes!!!! clear worked :)\n" : std::cout <<  RED <<"🦀noooo clear failed :(\n";
	std::cout << BOLDBLACK << "copy containers size = " << test.size() << std::endl;
	std::cout << "\n";
	std::cout << "\n";

	std::cout << YELLOW << "test de count" << std::endl;
	NAMESPACE::map<char,int> mymap;
	char c;

	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;
	
	std::cout << BOLDBLACK << "on doit trouver a, c et f!!!" << std::endl;
	for (c='a'; c<'h'; c++)
	{
		std::cout << c;
		if (mymap.count(c)>0)
		std::cout << BOLDGREEN << " est un elem ds ma map!!!\n" << RESET;
		else 
		std::cout << RED << " n'est pas un elem de ma map!!!!!\n" << RESET;
	}

	std::cout << "\n";
	std::cout << "\n";

  		NAMESPACE::map<char,int> mymap1;

		std::cout << BOLDYELLOW << "test de equal range" << std::endl;
		mymap1['a']=20;
		mymap1['b']=40;
		mymap1['c']=60;
		mymap1['d']=80;
		mymap1['e']=100;
		NAMESPACE::pair<NAMESPACE::map<char,int>::iterator,NAMESPACE::map<char,int>::iterator> ret;
		ret = mymap1.equal_range('b');
		std::cout << BOLDWHITE << "lower bound points to: ";
		std::cout << BOLDBLUE << ret.first->first << " => " << YELLOW << ret.first->second << '\n';
		std::cout << BOLDWHITE <<  "upper bound points to: ";
		std::cout << BOLDBLUE << ret.second->first << " => " <<YELLOW << ret.second->second << '\n';

		NAMESPACE::map<char,int>::iterator itlow,itup;
		std::cout << BOLDWHITE << "test de lower_bound de 'b' \n" << RESET;
		itlow=mymap1.lower_bound ('b');  
		std::cout << BOLDWHITE << "test de upper_bound de 'd' \n" << RESET;
		itup=mymap1.upper_bound ('d');   

		mymap1.erase(itlow,itup); 
		for (NAMESPACE::map<char,int>::iterator it=mymap1.begin(); it!=mymap1.end(); ++it)
	    std::cout << BOLDBLUE << it->first << " => " << YELLOW << it->second << '\n';


		std::cout << "\n";
		std::cout << "\n";
		std::cout << BOLDYELLOW << "test de erase " << std::endl;
		std::cout << BOLDYELLOW << "to do " << std::endl;
		std::cout << "\n";
		std::cout << "\n";

		std::cout << BOLDYELLOW << "test de find " << std::endl;
		NAMESPACE::map<char,int> mymap2;
		NAMESPACE::map<char,int>::iterator it1;
		
		mymap2['a']=50;
		mymap2['b']=100;
		mymap2['c']=150;
		mymap2['d']=200;
		
		
		std::cout << BOLDWHITE << "elements de ma map:" << '\n';
		std::cout << BOLDBLUE << "a => " << BOLDYELLOW << mymap2.find('a')->second << '\n';
		std::cout << BOLDBLUE << "b => " << BOLDYELLOW << mymap2.find('b')->second << '\n';
		std::cout << BOLDBLUE << "c => " << BOLDYELLOW << mymap2.find('c')->second << '\n';
		std::cout << BOLDBLUE << "d => " << BOLDYELLOW << mymap2.find('d')->second << '\n';
		std::cout << BOLDBLUE << "f qui n'existe pas et qui doit renvoyer end => " << BOLDYELLOW << mymap2.find('f')->second << '\n';

		std::cout << "\n";
		std::cout << "\n";
		std::cout << BOLDYELLOW << "test de insert " << std::endl;

		NAMESPACE::map<char,int> lolilol;
		std::cout << BOLDYELLOW<< "test de insert number uno avec 1 seul param ---- const value type, un vrai plaisir" << std::endl;
		std::cout << BOLDBLACK<< "je creer une premiere map ou" << std::endl;

		// first insert function version (single parameter):
		std::cout << BOLDBLACK << "j'insere deux vals + keys a100 et z200" << std::endl;
		lolilol.insert ( NAMESPACE::pair<char,int>('a',100) );
		lolilol.insert ( NAMESPACE::pair<char,int>('z',200) );

		NAMESPACE::pair<NAMESPACE::map<char,int>::iterator,bool> ret1;
		ret1 = lolilol.insert ( NAMESPACE::pair<char,int>('z',500));
		if (ret1.second ==false) {
			std::cout << RED <<  "l'element 'z' existe deja";
			std::cout << BOLDGREEN <<  " avec une valeur de " << ret1.first->second << '\n';
		}

		// second insert function version (with hint position):
		std::cout << BOLDYELLOW<< "test de insert num 2 avec une position donnee" << std::endl;

		NAMESPACE::map<char,int>::iterator it3 = lolilol.begin();
		std::cout << BOLDBLACK << "j'insere deux autres vals + keys b300 et c400" << std::endl;
		lolilol.insert (it3, NAMESPACE::pair<char,int>('b',300));  // max efficiency inserting
		lolilol.insert (it3, NAMESPACE::pair<char,int>('c',400));  // no max efficiency inserting

		// third insert function version (range insertion):

		std::cout << BOLDYELLOW<< "test de insert num 3 avec une range insertion" << std::endl;
		std::cout << BOLDBLACK<< "je creer une seconde map ou j'insere le contenu de la first map jusqua c" << std::endl;

		NAMESPACE::map<char,int> anothermap;
		anothermap.insert(lolilol.begin(),lolilol.find('c'));

		// showing contents:
		std::cout << BOLDWHITE <<  "la first map contient :\n";
		for (it3=lolilol.begin(); it3!=lolilol.end(); ++it3)
			std::cout << BOLDBLUE << it3->first << " => " << BOLDYELLOW << it3->second << '\n';

		std::cout << BOLDWHITE << "la deuxieme map contient:\n";
		for (it3=anothermap.begin(); it3!=anothermap.end(); ++it3)
			std::cout << BOLDBLUE << it3->first << " => " << BOLDYELLOW << it3->second << '\n';


		std::cout << "\n";
		std::cout << "\n";
		std::cout << BOLDYELLOW<< "test de maxsize" << std::endl;
		
		int i;
		NAMESPACE::map<int,int> coucou;
		
		if (coucou.max_size()>1000)
		{
			for (i=0; i<1000; i++) coucou[i]=0;
		std::cout << BOLDBLACK<< "on raj 1000 elem ds notre map" << std::endl;
			std::cout <<BOLDGREEN << "The map contains 1000 elements.\n";
		}
		else std::cout << "The map could not hold 1000 elements.\n";


		std::cout << "\n";
		std::cout << "\n";
		std::cout << BOLDYELLOW<< "test de swap" << std::endl;
		
		NAMESPACE::map<char,int> foo,bar;
		
		foo['x']=100;
		foo['y']=200;
		
		bar['a']=11;
		bar['b']=22;
		bar['c']=33;
		
		std::cout << "foo contains:\n";
		for (NAMESPACE::map<char,int>::iterator itera=foo.begin(); itera!=foo.end(); ++itera)
			std::cout << BOLDBLUE << itera->first << " => " << BOLDYELLOW << itera->second << '\n';
		
		std::cout << "bar contains:\n";
		for (NAMESPACE::map<char,int>::iterator iter=bar.begin(); iter!=bar.end(); ++iter)
			std::cout <<BOLDBLUE << iter->first << " => " << BOLDYELLOW << iter->second << '\n';
		std::cout << "\n";
		
		std::cout << BOLDGREEN << "on swap foo et bar de place" << std::endl;
		foo.swap(bar);
		std::cout << "\n";
		
		std::cout << "foo contains:\n";
		for (NAMESPACE::map<char,int>::iterator itera=foo.begin(); itera!=foo.end(); ++itera)
			std::cout << BOLDBLUE <<itera->first << " => " << BOLDYELLOW << itera->second << '\n';
		
		std::cout << "bar contains:\n";
		for (NAMESPACE::map<char,int>::iterator iter=bar.begin(); iter!=bar.end(); ++iter)
			std::cout << BOLDBLUE <<iter->first << " => " <<BOLDYELLOW <<  iter->second << '\n';
		

}
