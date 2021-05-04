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

std::vector<std::vector<std::vector<std::string>>> set_vectors;
std::vector<vector<string>> block_vectors;
std::vector<string> cache_vector;

int no_of_blocks_in_cache =0;
int no_of_words_in_block =0;
int no_of_blocks_in_set = 0;
int no_of_sets_in_cache = 0;

int cache_size = 0;
int block_size = 0;
int word_size = 0;

int add_count = 0;
int line_count = 0;
void display_cache(){
  for (int k = 0; k < no_of_sets_in_cache; k++) {
    std::cout << "set -" <<k << '\n';
    for (int i = 0; i < no_of_blocks_in_set; i++) {
        std::cout << "block -" <<i << '\n';
        for (int j = 0; j < no_of_words_in_block; j++) {
          std::cout <<"word -" <<j<<" "<<set_vectors[k][i][j] << '\n';
        }
        std::cout  << '\n';
    }
}
}

int mapping_function(){

      add_count =0;
      // no of sets in cache or set word_size
      // no of blocks in sets
      // no of words in blocks
      no_of_sets_in_cache = (cache_size*1024) / (no_of_blocks_in_set * no_of_words_in_block * word_size);
      std::cout <<"no of sets in cache: "<<  no_of_sets_in_cache << '\n';
      for (int k = 0; k < no_of_sets_in_cache; k++) {
        for (int i = 0; i < no_of_blocks_in_set && add_count < line_count; i++) {
            std::vector<string> temp;
            for (int j = 0; j < no_of_words_in_block; j++) {
              temp.push_back(cache_vector[add_count]);
              add_count++;
            }
            block_vectors.push_back(temp);
        }
        set_vectors.push_back(block_vectors);
      }

      return 0;
}



  int  direct_mapping(){
    std::cout << "direct_mapping" << '\n';
    std::cout << "It is nothing but 1 way set_associative_mapping having 1 block in each set!" << '\n';

    cout << "mapping - done " << mapping_function() <<"\n";

    return 0;
  }
  int set_associative_mapping(){
    std::cout << "set_associative_mapping" << '\n';
    mapping_function();
    return 0;
  }
  int fully_associative_mapping(){
    std::cout << "fully_associative_mapping" << '\n';
    std::cout << "It is nothing but n way set_associative_mapping having n block in each set, that is whole cache is 1 set!" << '\n';
    mapping_function();
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

  int lru_replacement(int add_count,int line_count){
    std::cout << "lru_replacement" << '\n';

    return 0;
  }
 int fifo_replacement(int add_count,int line_count){
   std::cout << "fifo_replacement" << '\n';
   // block_vectors, add_count, line_count
       int k = 0;
       for (int i = 0; i < no_of_blocks_in_cache && add_count < line_count; i++) {
           std::vector<string> temp;
           for (int j = 0; j < no_of_words_in_block; j++) {
             temp.push_back(cache_vector[add_count]);
             add_count++;
           }
           block_vectors[k] = temp;
       }
       k++;
       if(add_count<=line_count){
         cout << fifo_replacement(add_count, line_count);
       }
       std::cout << "After Replacement:!!" << '\n';
       display_cache();
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
  //int cache_size=0;
  //int block_size=0;
  //int word_size=0;
  int mapping=0;
  // need to take these variable values from config file.
// trace file
 //  FILE *fp_trace;
  std::ifstream fp_trace;
//  fp_trace.open("cache_trace_file.trc");
 fp_trace.open("trace_test-2.trc");
// config file
  std::ifstream fp_config;
  fp_config.open("cache_configure.cfg");
// output file
 //FILE *fp_output;
//fp_output = fopen("output_stats.txt","w");


//  code to redirect output to file

    std::ofstream out("output.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

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


  std::string add1, insttype;
  string input_line;
  line_count =0;
  for(int i=0;i<620;i++){
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
no_of_blocks_in_cache = (cache_size * 1024) / block_size;
no_of_words_in_block = block_size / word_size;
//int no_of_blocks_in_set = 0;
if(mapping==0){
  no_of_blocks_in_set = 1;
}
else if (mapping==1){
  // k way set associative -- take k as input from user if possible
  no_of_blocks_in_set = 2;
}
else if(mapping==2){
  no_of_blocks_in_set = no_of_blocks_in_cache;
}
std::cout << "no_of_blocks_in_cache" << no_of_blocks_in_cache << '\n';
std::cout << "no of blocks in set: " <<no_of_blocks_in_set<< '\n';
std::cout << "no_of_words_in_block" <<no_of_words_in_block <<'\n';
std::cout << "no_of_sets_in_cache " << no_of_sets_in_cache << '\n';
  //mapping_function();

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

  display_cache();

  // replacement is needed bcoz cache is full but address are still pending
  int replace = 1; // default is fifo
  std::cout << "add_count" <<add_count<< '\n';
  std::cout << "line_count" <<line_count<< '\n';

  if(add_count<=line_count){
      switch(replace) {
        case 0: cout << lru_replacement(add_count, line_count);
                break;
        case 1: cout << fifo_replacement(add_count, line_count);
                break;
        case 2: cout << random_replacement();
                break;
      }
  }


  // need to take input from trace file and add that into a hashset
  // then based on config files, we need to have a cache vector(bcoz order is also important)
  // but also have a cache set to quickly check for hit or miss.
  //cache should of given size
  // each address will take word_size
  // block_size is used in mapping type
  //fclose(fp_trace);
  //fclose(fp_config);
//fclose(fp_output);
  return 0;
}
