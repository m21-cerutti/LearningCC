#include <iostream>
#include <fstream>

#include <string>

#include <cmath>
#include <bitset>

#include <algorithm>
#include <cctype>
#include <functional>

// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

#include <iterator>

#include <vector>
#include <array>

#include <map>
#include <unordered_map>

#include <set>
#include <unordered_set>

#include <stack>
#include <queue>

//optionnal
#include <complex>

using namespace std;

//using = typedef

int main()
{

	/*
	Functionnalities useful for namesspaces
	*/
	//using namespace std;
	//using std::cout;

	cout << "Hello world!" << endl;
	//endl ->\n
	cout << "Tests variables" << endl;
	int testVarInt ( 16 );
	char testVarChar = 65;
	cout << testVarInt << endl;
	cout << testVarChar << endl;
	cout << testVarInt + 2 << endl;
	testVarInt = 2;
	testVarChar = 'X';
	cout << testVarInt << endl;
	cout << testVarChar << endl;

	/*Sorites standart*/

	/*

	cout et wcout pour les messages standard ;
	cerr et wcerr pour les messages d'erreur ;
	clog et wclog pour les messages de log.

	w correspond à wide, et prend les carractères étendues pour les messages.

	<< coresspond à l'envoie dans le flux

	*/
	cout << "Tests bases" << endl;
	cout << "Affichage" << endl;


	cout << R"*(Affichage sans carract (special \\\\ \n))*" << endl;

	/*Base affichage
	(std::oct, std::dec et std::hex)
	std::showbase montre la base d'affichage
	*/
	std::cout << std::showbase << 0x10 << std::endl;
	std::cout << std::hex << 10 << std::endl;

	std::cout << "0b" << std::bitset<8> ( 3 ) << std::endl;
	std::cout << "0b" << std::bitset<4> ( 3 ) << std::endl;
	std::cout << std::endl;
	std::cout << std::dec << std::showbase;
	std::cout << ( 0b11011000 << 1 ) << std::endl; // décalage de 1 bit à gauche
	std::cout << ( 0b11011000 << 2 ) << std::endl; // décalage de 2 bit à gauche
	std::cout << std::endl;
	std::cout << ( 0b11011000 >> 1 ) << std::endl; // décalage de 1 bit à droite
	std::cout << ( 0b11011000 >> 2 ) << std::endl; // décalage de 2 bit à droite

	std::cout << "Constante de Planck = " << 6.62606957e-34 << " kg.m²/s" << std::endl;

	/*affichage scientifique */
	cout << "Scientifique" << endl;
	std::cout << "Pi" << std::endl;
	std::cout << " Notation scientifique : " << std::scientific << 3.1415926535 << std::endl;
	std::cout << " Notation fixe :         " << std::fixed << 3.1415926535 << std::endl;
	std::cout << " Notation par defaut :   " << std::defaultfloat << 3.1415926535 << std::endl;
	std::cout << std::endl;
	/*Boolean
	std::boolalpha
	*/

	/*Infinité sur les réels


	std::isinf() pour tester si une valeur est infinie ;
	std::isnan() pour tester si une valeur est pas-un-nombre ;
	std::isfinite() pour tester si une valeur est finie, c'est-à-dire qu'elle n'est ni infinie, ni pas-un-nombre.


	*/
	cout << "Infinity" << endl;
	std::cout << "Infini : " << INFINITY << std::endl;
	std::cout << "Pas-un-nombre : " << NAN << std::endl;


	/*Conversion string, int */
	cout << "Conversion" << endl;
	std::string int_str { "123" };
	int const i { std::stoi ( int_str ) };
	std::cout << i << std::endl;

	std::string double_str { "123.456" };
	auto const d = std::stod ( double_str );
	std::cout << d << std::endl;
	{
		using namespace std::literals;
		cout << "Complex" << endl;
		std::cout << "2+3i = " << ( 2.0 + 3.0i ) << std::endl;
	}

	cout << endl;
	cout << "Enumerations" << endl;
	cout << endl;
	/*:: (scope operator) accés aux valeurs*/
	enum class Couleur
	{
		Noir, Blanc = 0, Rouge, Jaune, Bleu, Orange, Vert, Violet
	};

	Couleur une_couleur { Couleur::Rouge };  // initialisation
	une_couleur = Couleur::Noir;             // affectation
	cout << std::dec << static_cast<int> ( une_couleur ) << endl;
	une_couleur = Couleur::Rouge;
	cout << std::dec << static_cast<int> ( une_couleur ) << endl;

	//enum global
	/*
	Ce type d'énumération ne nécessite pas de conversion
	explicite avec static_cast pour convertir en entier,
	les valeurs sont convertie implicitement (promotion) entiers.
	*/
	enum Pion
	{
		Tour, Fou
	};


	cout << endl;
	cout << "TYPES avance" << endl;
	cout << endl;
	/*Astuce sur les types


	auto : déduit le type à partir de VALEUR, sans conserver les modificateurs de types (const, etc.) ;
	decltype(auto) : déduit le type à partir de VALEUR, en conservant les modificateurs de types;
	decltype(expression) : déduit le type d'une expression.
	*/

	std::cout << "sizeof(int) = " << sizeof ( int ) << std::endl;
	std::cout << "sizeof(double) = " << sizeof ( double ) << std::endl;
	std::cout << "sizeof(bool) = " << sizeof ( bool ) << std::endl;
	std::cout << "sizeof(char) = " << sizeof ( char ) << std::endl;

	std::string const s1 { "hello, world!" };
	std::string const s2 { "Bonjour tout le monde !" };
	std::cout << "sizeof(s1) = " << sizeof ( s1 ) << std::endl;
	std::cout << "sizeof(s2) = " << sizeof ( s2 ) << std::endl;
	std::cout << "s1.size() = " << s1.size() << std::endl;
	std::cout << "s2.size() = " << s2.size() << std::endl;

	//unsigned int const ui { 123u };
	//float const f { 123.456f };
	cout << endl;
	cout << "Alias" << endl;
	cout << endl;
	using uint = unsigned int;

	uint var = -13;
	cout << var << endl;

	cout << endl;
	cout << "Structures de donnees" << endl;
	cout << endl;


	std::string s {};

	// début de la collection
	s.begin();      // fonction membre
	std::begin ( s ); // fonction libre

	// fin de la collection
	s.end();        // fonction membre
	std::end ( s ); // fonction libre

	s = "azertybc" ;
	std::sort ( std::begin ( s ), std::end ( s ) - 1 );
	std::cout << s << std::endl;

	std::vector<int> v { 1, 2, 3 };
	//std::cout << v << std::endl; // erreur

	std::vector<int> integers_var {};


	cout << endl;
	cout << "Templates" << endl;
	cout << endl;
	/*
	template_class<int>  ;              // classe template avec 1 argument
	another_template_class<int, float>; // classe template avec 2 arguments

	template_function<int>();          // une fonction template

	foo<arg1, arg2>(arg3, arg4);
	*/

	// tableau d'entiers, la taille peut changer à l'exécution
	std::vector<int> const integers_1 {};

	// tableau de 5 nombres réels, la taille est fixe
	std::array<float, 5> floats {2.5, 3, 6, 8}; // par défaut 0

	std::vector<int> integers_2{1}; // crée un tableau contenant 5 éléments () constructeur, {} valeurs

	std::cout << "Size of vector is " << integers_2.size() << std::endl;
	std::cout << "Size of array is " << floats.size() << std::endl;

	cout << endl;
	cout << "Itineration and manipulation" << endl;
	cout << endl;

	std::vector<int> v_2 { 1, 2, 3 };
	// v contient { 1, 2, 3 }

	v.push_back ( 4 );
	std::cout << v.back() << std::endl;
	// v contient { 1, 2, 3, 4 }

	v.back() = 5;
	std::cout << v.back() << std::endl;
	// v contient { 1, 2, 3, 5 }

	v.pop_back();
	v.pop_back();
	std::cout << v.back() << std::endl;
	// v contient { 1, 2 }

	cout << endl;
	cout << "Copy std" << endl;
	cout << endl;
	//copie dans la sortie standart
	std::vector<int> const newv { 1, 2, 3, 4 };
	copy ( begin ( newv ), end ( newv ), std::ostream_iterator<int> ( std::cout, "\t" ) );
	std::cout << std::endl;

	cout << endl;
	cout << "loop for" << endl;
	cout << endl;

	for ( auto const value : newv )
	{ std::cout << value << std::endl; }

	cout << endl;
	cout << "Map, dico" << endl;
	cout << endl;
	//Il existe des conteneurs associatif (dico ex) et non associatif (liste)

	const std::map<int, std::string> m
	{
		{ 2, "hello" },
		{ 3, "every" },
		{ 1, "body" }
	};

	for ( auto p : m )
	{
		std::cout << p.first << ' ' << p.second << std::endl;
	}

	cout << endl;
	cout << "cassert" << endl;
	cout << endl;

	//Astuce verif tableaux
	std::vector<int> const vecttab { 1, 2, 3, 4 };
	const int ind {2};
	//const int ind {6}; //Assertion failed line etc + windows fermer programme
	assert ( ind > 0 && ind < vecttab.size() );
	v[ind];

	/*

	reserve(n) permet d'augmenter la taille de la réserve en mémoire.
	Cette fonction prend en paramètre le nombre d'éléments total que vous souhaitez.
	La réserve est augmentée uniquement si vous demandez plus que la réserve actuelle.

	shrink_to_fit() permet de réduire au maximum la taille de la réserve,
	de façon à ce que la taille totale correspond au nombre d'éléments réellement utilisés.
	(Autrement dit, la réserve sera mise à zéro).

	size() permet de connaître le nombre total d'élément actuellement utilisés dans le tableau.
	capacity() permet de connaître le nombre totale d'élément dans le tableau (utilisés et réserve).
	max_size() permet de connaître le nombre maximal d'élément qu'il sera possible d'avoir dans un tableau.
	empty() permet de savoir si un tableau ne contient pas d'élément utilisé (autrement dit, si size() vaut zéro).

	 std::vector<int> v(100) et v.reserve(100).
	 La première syntaxe crée un tableau qui contient 100 éléments
	 (la taille de la réserve est choisie automatiquement),
	 la seconde crée un tableau vide (0 élément), mais qui contient 100 éléments dans la réserve.
	*/

	cout << endl;
	cout << "Map" << endl;
	cout << endl;
	//std::map dont toutes les clés sont distinctes (l'insertion d'un élément avec une clé existante échouera) ;

	//std::multimapqui peut contenir plusieurs éléments utilisant la même clé.

	std::map<int, std::string> m1
	{
		{ 1, "hello" },
		{ 2, "world" }
	};
	m1.emplace ( 2, "everyone" );

	for ( auto p : m1 )
	{ std::cout << p.first << ' ' << p.second << std::endl; }

	std::cout << std::endl;

	std::multimap<int, std::string> mm
	{
		{ 1, "hello" },
		{ 2, "world" }
	};
	mm.emplace ( 2, "everyone" );

	for ( auto p : mm )
	{ std::cout << p.first << ' ' << p.second << std::endl; }

	cout << endl;
	cout << "HMap" << endl;
	cout << endl;

	std::unordered_map<int, std::string> mh
	{
		{ 1, "hello" },
		{ 2, "world" }
	};
	mh.emplace ( 2, "everyone" );

	for ( auto p : mh )
	{ std::cout << p.first << ' ' << p.second << std::endl; }

	std::cout << std::endl;

	std::unordered_multimap<int, std::string> mmh
	{
		{ 1, "hello" },
		{ 2, "world" }
	};
	mmh.emplace ( 2, "everyone" );

	for ( auto p : mmh )
	{ std::cout << p.first << ' ' << p.second << std::endl; }

	cout << endl;
	cout << "Sets(ensembles, <cle unique>)" << endl;
	cout << endl;
	/*
	std::set ;
	std::multiset ;
	std::unordered_set ;
	std::unordered_multiset.
	*/
	std::set<std::string> set1
	{
		{ "hello" },
		{ "world" }
	};
	set1.emplace ( "everyone" );

	for ( auto v : set1 )
	{ std::cout << v << std::endl; }

	cout << endl;
	cout << "Types non internes" << endl;
	cout << endl;

	cout << endl;
	cout << "Stack" << endl;
	cout << endl;
	/*
	 push permet d'ajouter un élément ;
	emplace permet de créer un élément directement sur le dessus de la pile ;
	pop permet de retirer un élément ;
	top permet d'accéder à l'élément sur le dessus de la pile ;
	empty permet de savoir si une pile est vide ;
	size permet de connaître le nombre d'éléments
	*/
	{
		std::stack<char> s;
		s.push ( 'a' );
		s.emplace ( 'b' );
		s.push ( 'c' );

		assert ( !s.empty() );
		s.pop();
		std::cout << s.top() << std::endl;
		std::cout << s.size() << std::endl;
	}

	cout << endl;
	cout << "Queue" << endl;
	cout << endl;

	/*
	push permet d'ajouter un élément ;
	emplace permet de créer un élément directement à l'entrée de la file ;
	pop permet de retirer un élément ;
	front permet d'accéder à l'élément à l'entrée de la file ;
	back permet d'accéder à l'élément à la sortie de la file ;
	empty permet de savoir si une file est vide ;
	size permet de connaître le nombre d'éléments.
	*/
	{
		std::queue<char> q;
		q.push ( 'a' );
		q.emplace ( 'b' );
		q.push ( 'c' );
		assert ( !q.empty() );
		q.pop();
		std::cout << q.front() << std::endl;
		std::cout << q.back() << std::endl;
		std::cout << q.size() << std::endl;
	}

	/*
	Le dernier type d'adaptateur est similaire à std::queue,
	sauf que les éléments sont triés. De fait, lorsque vous retirer un élément de la queue,
	c'est celui qui a la plus grande valeur qui sort en premier.
	*/

	/*
	La différence entre emplace et push est que la première va créer un élément directement dans la collection,
	alors que la seconde va ajouter dans la collection un élément existant.
	Vous avez vu que certains types sont déplaçables (movable),
	utiliser push sur ce type d'élément ne sera généralement pas coûteux.
	Mais lorsque c'est possible, il sera toujours plus performant d'utiliser directement emplace.

	Insert et emplace meme chose. il n'y aura pas de différence entre insert et emplace,
	mais cela sera important lorsque vous souhaiterez insérer des éléments complexes.
	*/

	cout << endl;
	cout << "Supression" << endl;
	cout << endl;
	{
		std::vector<int> v { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		auto first = std::find ( begin ( v ), end ( v ), 3 );
		auto last  = std::find ( begin ( v ), end ( v ), 7 );
		v.erase ( first, last );

		for ( auto i : v )
		{
			std::cout << i << ' ';
		}

		std::cout << std::endl;
	}
	/*
	{
	    std::vector<char> v { 'a', '1', 'b', '2', 'c', '3' };
	    auto it = std::remove_if(begin(v), end(v), std::isdigit);
	    v.erase(it, end(v));
	    for (auto i: v) std::cout << i << ' ';
	    std::cout << std::endl;
	}
	*/

	/*


	cet algorithme est défini dans le fichier d'en-tête <algorithm>, il faudra donc l'inclure dans votre code pour utiliser std::equal ;
	il existe quatre versions de cet algorithme :
	    le premier prend en argument le début et la fin d'une première collection et le début d'une seconde collection ;
	    le second est similaire au premier, avec un prédicat personnalisé ;
	    la troisième prend en argument le début et la fin de la première collection, puis de la seconde ;
	    le quatrième est similaire au troisième, avec un prédicat personnalisé.
	le prédicat doit respecter la signature suivante : bool pred(const Type1 &a, const Type2 &b);.
	C'est donc une fonction binaire - une fonction qui prend deux arguments - et retourne un booléen.

	*/

	cout << endl;
	cout << "Predicat de base et booleen" << endl;
	cout << endl;

	//opérateurs logiques (logical_and, logical_or et logical_not) et de comparaison (equal_to, not_equal_to, greater, less, greater_equal et less_equal)
	const auto predicat = std::equal_to<>();
	std::cout << std::boolalpha << predicat ( 1, 2 ) << std::endl;
	// Il est possible de spécifier le type du prédicat entre les chevrons (ce qui produira une erreur
	//si vous essayez d'utiliser le prédicat avec un type non compatible)
	//ou de laisser les chevrons vides pour accepter n'importe quel type comparable.

	cout << endl;
	cout << "Inferiorite, etc de collections " << endl;
	cout << endl;
	std::cout << std::boolalpha;
	std::cout << ( std::string { "abc" } < std::string { "acd" } ) << std::endl;
	std::cout << ( std::string { "abc" } < std::string { "ab" } ) << std::endl;
	std::cout << ( std::vector<int> { 1, 2, 3 } < std::vector<int> { 1, 2, 4 } ) << std::endl;
	std::cout << ( std::vector<int> { 1, 2, 3 } < std::vector<int> { 1, 2 } ) << std::endl;

	//std::lexicographical_compare utile aussi
	//std::toupper(c) pour la casse
	cout << endl;
	cout << "Cas de la casse de mots" << endl;
	cout << endl;
	{
		std::string const s1 { "ABCDEF" };
		std::string const s2 { "azerty" };
		std::cout << std::boolalpha;
		std::cout << std::lexicographical_compare ( begin ( s1 ), end ( s1 ), begin ( s2 ), end ( s2 ) ) << std::endl;
		std::cout << std::equal ( begin ( s1 ), end ( s1 ), begin ( s2 ), end ( s2 ),
		[] ( auto lhs, auto rhs ) { return std::toupper ( lhs ) < std::toupper ( rhs ); } )
		        << std::endl;
	}

	cout << endl;
	cout << "Iterateur" << endl;
	cout << endl;
	{
		std::vector<int> v{5, 1, 2, 3, 4};

		std::vector<int>::iterator first_not_cut { std::begin ( v ) };
		//ou
		const auto first = std::begin ( v );
		const auto last = std::end ( v );

		std::sort ( first, last );

		for ( auto i : v )
		{
			std::cout << i << ' ';
		}

		std::cout << std::endl;

		std::random_shuffle ( first_not_cut, last );

		for ( auto i : v )
		{
			std::cout << i << ' ';
		}

		std::cout << std::endl;
	}
	cout << endl;
	cout << "Iterateur reverse et constantes" << endl;
	cout << endl;
	/*
	c pour itérateurs constant et r pour itérateur reverse
	std::begin et std::end ;
	std::rbegin et std::rend ;
	std::cbegin et std::cend ;
	std::crbegin et std::crend.

	*/
	{
		std::string s { "azerty" };
		std::sort ( std::begin ( s ), std::end ( s ) );
		std::cout << s << std::endl;
		std::sort ( std::rbegin ( s ), std::rend ( s ) );
		std::cout << s << std::endl;
	}

	{
		std::string s1 { "azerty" };

		std::string s2 ( std::begin ( s1 ), end ( s1 ) );
		std::cout << s2 << std::endl;

		std::string s3 ( std::begin ( s1 ), std::begin ( s1 ) + 3 );
		std::cout << s3 << std::endl;
	}

	cout << endl;
	cout << "Iterateur avec find " << endl;
	cout << endl;
	{
		const std::string s { "f9c02b6c9da8943feaea4966ba7417d65de2fe7e" };
		const auto it = std::find ( std::begin ( s ), std::end ( s ), '8' );
		std::cout << std::string ( std::begin ( s ), it ) << std::endl;
		std::cout << std::string ( it, std::end ( s ) ) << std::endl;
	}
	cout << endl;
	cout << R"*(/!\ std::end cas particulier (peut faire comme un Null(c++ nulptr)))*" << endl;
	cout << endl;
	//ATTENTION std::end élément imaginaire de fin, pas le dernier elem.
	{
		const std::string s { "abcdefghijk" };
		const auto it = std::find ( std::begin ( s ), std::end ( s ), '1' );
		std::cout << std::boolalpha << ( it == std::end ( s ) ) << std::endl;
	}

	cout << endl;
	cout << "Notion d'indirection" << endl;
	cout << endl;
	/*
	 Il existe plusieurs types d'indirection en C++ : les références, les pointeurs et les itérateurs.
	 Les syntaxes présentent quelques différences, mais également des principes communs.
	 Les itérateurs sont utilisés avec les collections, les références et pointeurs seront utilisés avec les fonctions
	(dans la partie “Créer ses algorithmes”) et l'allocation dynamique (dans la partie Programmation Orientée Objet).

	Une indirection permet d'accéder indirectement à un autre objet, pour pouvoir lire la valeur ou la modifier.
	Accéder à l'élément correspondant à une indirection s'appelle “déréférencer une indirection”. Pour les itérateurs,
	l'accès se fait en utilisant l'opérateur * unaire préfixé
	*/

	{
		std::string s { "abcdef" };
		const auto it = std::begin ( s );
		std::cout << s << std::endl;
		( *it ) = 'A';
		std::cout << s << std::endl;
	}

	cout << endl;
	cout << "ecriture et lecture de fichier" << endl;
	cout << endl;
	/*
	td::ios::binary : ouverture en mode binaire ;

	std::ios::in : en lecture (pour fstream) ;
	std::ios::out : en écriture (pour fstream) ;

	std::ios::app (append = “ajouter”) : ajoute à la fin du fichier ;
	std::ios::trunc (truncate = “tronquer”) : supprimer le contenu ;
	std::ios::ate (at the end = “à la fin”) : ajoute à la fin lors de l'ouverture.

	*/

	/********************************************//**
	 * \brief test
	 *
	 * \param
	 * \param
	 * \return
	 *
	 ***********************************************/

	{
		std::ofstream file { "test.txt" };
		file << "Hello word! " << std::endl;
	}
	{
		// creation du fichier
		std::ofstream out { "test.txt", std::ios::app };
		out << 123 << std::endl;
	}
	{
		std::ifstream in { "test.txt" };
		string content;
		getline ( in, content );
		cout << content << endl;
		int i {};
		in >> i;
		std::cout << i << std::endl;
	}



















	system ( "PAUSE" );
	return 0;
}

/********************************************//**
 * \brief Fun function
 *
 * \param
 * \param
 * \return
 *
 ***********************************************/

void Fun()
{

}
