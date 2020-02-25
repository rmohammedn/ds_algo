#include <iostream>
#include <string>
#include <stack>


/* C++ program to simplify a Unix 
styled absolute path of a file */
#include <bits/stdc++.h> 
using namespace std; 

// function to simplify a Unix - styled 
// absolute path 
string simplify(string A) 
{ 
	// stack to store the file's names. 
	stack<string> st; 

	// temporary string which stores the extracted 
	// directory name or commands("." / "..") 
	// Eg. "/a/b/../." 
	// dir will contain "a", "b", "..", "."; 
	string dir; 

	// contains resultant simplifies string. 
	string res; 

	// every string starts from root directory. 
	res.append("/"); 

	// stores length of input string. 
	int len_A = A.length(); 

	for (int i = 0; i < len_A; i++) { 
		dir.clear(); 

		while (A[i] == '/') 
			i++; 


		while (i < len_A && A[i] != '/') { 
			dir.push_back(A[i]); 
			i++; 
		} 


		if (dir.compare("..") == 0) { 
			if (!st.empty()) 
				st.pop();			 
		} 

		// if dir has "." then simply continue 
		// with the process. 
		else if (dir.compare(".") == 0) 
			continue; 
		
		// pushes if it encounters directory's 
		// name("a", "b"). 
		else if (dir.length() != 0) 
			st.push(dir);		 
	} 
	stack<string> st1; 
	while (!st.empty()) { 
		st1.push(st.top()); 
		st.pop(); 
	} 
	while (!st1.empty()) { 
		string temp = st1.top(); 

		if (st1.size() != 1) 
			res.append(temp + "/"); 
		else
			res.append(temp); 

		st1.pop(); 
	} 
	return res; 
} 

