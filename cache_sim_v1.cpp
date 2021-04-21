#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include <fstream>
#include <cstdio>

//#include<hashset>

using namespace std;

//direct_mapping();
//set_associative_mapping();
//fully_associative_mapping();
//own_type_mapping();
  int  direct_mapping(){
    std::cout << "direct_mapping" << '\n';
    return 0;
  }
  int set_associative_mapping(){
    std::cout << "set_associative_mapping" << '\n';
    return 0;
  }
  int fully_associative_mapping(){
    std::cout << "fully_associative_mapping" << '\n';
    return 0;
  }
  int own_type_mapping(){
    std::cout << "own_type_mapping" << '\n';
    return 0;
  }
// lru_replacement();
// fifo_replacement();
// random_replacement();
// own_replacement();

  int lru_replacement(){
    std::cout << "lru_replacement" << '\n';
    return 0;
  }
 int fifo_replacement(){
   std::cout << "fifo_replacement" << '\n';
   return 0;
  }
int   random_replacement(){
  std::cout << "random_replacement" << '\n';
return 0;
  }
int   own_replacement(){
  std::cout << "own_replacement" << '\n';
return 0;
  }


int main() {
  int cache_size=0;
  int block_size=0;
  int word_size=0;
  int mapping=0;
  // need to take these variable values from config file.
// trace file
 //  FILE *fp_trace;
  std::ifstream fp_trace;
//  fp_trace.open("cache_trace_file.trc");
 fp_trace.open("trace_test-1.trc");
// config file
  std::ifstream fp_config;
  fp_config.open("cache_configure.cfg");
// output file
//  FILE *fp_output;
//  fp_output = fopen("output_stats.txt","w");


//  code to redirect output to file
/*
    std::ofstream out("output.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
*/
  //freopen("output.txt","w",stdout);
//

  string in_line;
  //for(int j=1;j<=4;j++){
    std::getline(fp_config,in_line);
    std::cout << in_line << '\n';
    std::string delim = " ";
    std::string rtoken =  in_line.substr(13,in_line.find(delim));
    //std::string lnumber = rtoken.substr(0,rtoken.find(" "));
    std::string number = rtoken.substr(0,rtoken.find(" "));
    std::cout << number << '\n';
      cache_size = std::stoi(number);

      std::getline(fp_config,in_line);
      std::cout << in_line << '\n';
      rtoken =  in_line.substr(13,in_line.find(delim));
      //std::string lnumber = rtoken.substr(0,rtoken.find(" "));
      number = rtoken.substr(0,rtoken.find(" "));
      std::cout << number << '\n';
      block_size = std::stoi(number);

      std::getline(fp_config,in_line);
      std::cout << in_line << '\n';
      rtoken =  in_line.substr(12,in_line.find(delim));
      //std::string lnumber = rtoken.substr(0,rtoken.find(" "));
      number = rtoken.substr(0,rtoken.find(" "));
      std::cout << number << '\n';
      word_size = std::stoi(number);


      std::getline(fp_config,in_line);
      std::cout << in_line << '\n';
      rtoken =  in_line.substr(10,in_line.find(delim));
      //std::string lnumber = rtoken.substr(0,rtoken.find(" "));
      number = rtoken.substr(0,rtoken.find(" "));
      std::cout << number << '\n';
      mapping = std::stoi(number);

  //}


  std::vector<string> cache_vector;
  std::string add1, insttype;
  string input_line;
  int line_count =0;
  for(int i=0;i<100;i++){
    std::getline(fp_trace,input_line);
    //fscanf(fp_trace, "%s\n",&input_line);
    // -1 in type denotes #
    //std::cout << input_line << '\n';
    std::string delimiter = ":";
    std::string address =  input_line.substr(0,input_line.find(delimiter));
    //std::string lnumber = rtoken.substr(0,rtoken.find(" "));
    //std::string number = rtoken.substr(0,rtoken.find(" "));
    //std::cout << address << '\n';
    add1 = address;
    cache_vector.push_back(add1);
    //cache_vector.push_back(add2);
    //std::cout << add1 << "\n";
    //printf("%d %d\n", add1, add2);
    line_count++;
  }

// each address/instruction takes 1 word_size memory
// each block can contain max block_size/word_size number of words.
// cache contains max cache_size/block_size number of blocks.
// cache is full when all blocks are filled.
// then go for lru_replacement
int no_of_blocks_in_cache = (cache_size * 1024) / block_size;
int no_of_words_in_block = block_size / word_size;

std::vector<vector<string>> block_vectors;
int add_count =0;
  for (int i = 0; i < no_of_blocks_in_cache && add_count < line_count; i++) {
      std::vector<string> temp;
      for (int j = 0; j < no_of_words_in_block; j++) {
        temp.push_back(cache_vector[add_count]);
        add_count++;
      }
      block_vectors.push_back(temp);
  }
  // replacement is needed bcoz cache is full but address are still pending
  int replace = 0; // default is lru
  if(add_count<=line_count){
      switch(replace) {
        case 0: cout << lru_replacement();
                break;
        case 1: cout << fifo_replacement();
                break;
        case 2: cout << random_replacement();
                break;
      }
  }

  for (int i = 0; i < no_of_blocks_in_cache; i++) {
      std::cout << "block -" <<i << '\n';
      for (int j = 0; j < no_of_words_in_block; j++) {
        std::cout <<"word -" <<j<<" "<<block_vectors[i][j] << '\n';
      }
      std::cout  << '\n';
  }

  switch(mapping) {
    case 0:
            cout << direct_mapping();
            break;
    case 1:
            cout << set_associative_mapping();
            break;
    case 2:
            cout << fully_associative_mapping();
            break;
    default:
            std::cout << "select correct mapping: direct map 0, set associative 1, fully associative 2" <<'\n';
  }
  // need to take input from trace file and add that into a hashset
  // then based on config files, we need to have a cache vector(bcoz order is also important)
  // but also have a cache set to quickly check for hit or miss.
  //cache should of given size
  // each address will take word_size
  // block_size is used in mapping type
  //fclose(fp_trace);
  //fclose(fp_config);
//  fclose(fp_output);
  return 0;
}
