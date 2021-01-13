#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include <iomanip>
#include<bits/stdc++.h> 

using namespace std;

int main(){
	// Creation of ifstream class object to read the file 
    ifstream fin; 
    
    // Destination string of getline function
    string line;
    
    // Vector to store individual lines of the file
    vector<string> my_file_vectorized;
  
    // Opening the file
    fin.open("Matthew C.txt"); 
    
    // Execute a loop until end of file 
    while (fin) { 
  
        // Read a Line from File 
        getline(fin, line); 
  
        // Store lines from file in vector 
        my_file_vectorized.push_back(line);
    } 
    
    // Close the file 
    fin.close(); 
    
    // Test to check encrypted file stored properly
	cout << "Testing Encrypted" << endl;
	for(int i = 0; i < 50; i++){
		cout << my_file_vectorized[i] << endl;
	}
	cout << endl;
	
	//Defining my alphabet
	char my_alphabet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	
	// Getting counts on individual letters of my alphabet
	int my_alphabet_counts[26]; //Array to store individual counts
	
	// Getting total character count for frequency calculation
	int total_char_count = 0;
	
	// Loop over alphabet
	for(int i = 0; i < 26; i++){
		int count = 0;
		
		// Loop over vectorized file
		for(int j = 0; j < my_file_vectorized.size(); j++){
			
			// Loop on string of individual line
			for(int k = 0; k < my_file_vectorized[j].length(); k++){
				if(my_file_vectorized[j].at(k) == my_alphabet[i]){ 
					count++;
				}
			}
		}
		
		my_alphabet_counts[i] = count;
		total_char_count += count;
		cout << my_alphabet[i] << " count is:" << my_alphabet_counts[i] << endl;
	}
	
	// Print total number of non-space characters
	cout << endl;
	cout << "The total number of non-space characters is: " << total_char_count << endl;
	
	// Creating an array to hold the relative frequencies of each letter of the alphabet
	double alphabet_frequencies[26];
	
	for(int i = 0; i < 26; i++){
		alphabet_frequencies[i] = (double)my_alphabet_counts[i] / (double)total_char_count*100;
		cout << "Frequency for " << my_alphabet[i] << " is " << alphabet_frequencies[i] << endl;
	}
	
	// To allign the proper letters with the frequencies I will use a sorting algorithm 
	double known_frequencies[26] = {8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094, 6.996, 0.153, 0.772, 4.025, 2.406, 6.749, 7.507, 1.929, 0.095, 5.987, 6.327, 9.056, 2.758, 0.978, 2.360, 0.150, 1.974, 0.074};
	//sort(known_frequencies, known_frequencies+26);
	//sort(alphabet_frequencies, alphabet_frequencies+26);
	
	// Displaying frequencies side by side to compare and put into key
	cout << endl;
	cout << "Alphabet Frequencies" << "		" << "Known Frequencies" << "		" << "Character" << endl;
	for(int i = 0; i < 26; i++){
		cout << setprecision(4) << alphabet_frequencies[i] << "				" << known_frequencies[i] << "				" << my_alphabet[i] << endl;
	}
	
	// Key for decryption calculated based on known frequencies
    char my_decryption_key[26] = {'A','U','X','H','K','O','P','F','W','E','Q','I','J','Z','V','Y','L','C','N','T','B','R','S','M','G','D'};
    
	// My alphabet for side by side reference
  	//		char my_alphabet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	
	// 2D vector to keep track of changed values so they are not changed again
	vector< vector<int> > value_changed;
	
	// Initializing all values of value_changed to false or 0
	for(int i = 0; i < my_file_vectorized.size(); i++){
		vector<int> temp;
		// Loop on string of individual line
		for(int j = 0; j < my_file_vectorized[i].length(); j++){
			
			if(&my_file_vectorized[i].at(j) != ""){ 
				temp.push_back(0);
			}
					
		}
		value_changed.push_back(temp);
	}
	
	// Loop that changes values to decrypt the message
	for(int i = 0; i < 26; i++){ // Loop over alphabet
		
		// Loop over vectorized file
		for(int j = 0; j < my_file_vectorized.size(); j++){
			
			// Loop on string of individual line
			for(int k = 0; k < my_file_vectorized[j].length(); k++){
				if(my_file_vectorized[j].at(k) == my_alphabet[i] && value_changed[j][k] == 0){ 
					my_file_vectorized[j].replace(k, 1, string(1,my_decryption_key[i])) ;
					//my_file_vectorized[j].at(k) = my_decryption_key[i];
					value_changed[j][k] = 1;
				}
			}
		}
	}
	
	
	// Test to check decryption
	cout << "Testing Decryption" << endl;
	for(int i = 0; i < 50; i++){
		cout << my_file_vectorized[i] << endl;
	}
	cout << endl;
	
	/*
	// Test value changed jagged vector
	cout << "Testing if values changed" << endl;
	for(int j = 0; j < 50; j++){
		
		// Loop on string of individual line
		for(int k = 0; k < my_file_vectorized[j].length(); k++){
			cout << value_changed[j][k] << " ";
		}
		cout << endl;
	}
	*/
	
	// Writing decrypted file to Matthew C Decrypted.txt
    ofstream fout; 
    
    fout.open("Matthew C Decrypted.txt");
    
    // Execute a loop If file successfully opened
	int my_index = 0; 
    while (fout && my_index < my_file_vectorized.size()) { 

        // Write line in file 
        fout << my_file_vectorized[my_index] << endl; 
        my_index++;
    } 
  
    // Close the File 
    fout.close(); 

	return 0;
}
