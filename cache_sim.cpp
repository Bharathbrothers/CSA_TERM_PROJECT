#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include <fstream>
//#include<hashset>

using namespace std;

//direct_mapping();
//set_associative_mapping();
//fully_associative_mapping();
//own_type_mapping();
  int  direct_mapping(){

    return 0;
  }
  int set_associative_mapping(){

    return 0;
  }
  int fully_associative_mapping(){

    return 0;
  }
  int own_type_mapping(){

    return 0;
  }
// lru_replacement();
// fifo_replacement();
// random_replacement();
// own_replacement();

  int lru_replacement(){

    return 0;
  }
 int fifo_replacement(){

   return 0;
  }
int   random_replacement(){
return 0;
  }
int   own_replacement(){
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
  fp_trace.open("cache_trace_file.trc");
// config file
  std::ifstream fp_config;
  fp_config.open("cache_configure.cfg");
// output file
  FILE *fp_output;
  fp_output = fopen("output_stats.txt","w");

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


  std::vector<int> cache_vector;
  int add1, insttype;
  string input_line;
  for(int i=0;i<10;i++){
    std::getline(fp_trace,input_line);
    //fscanf(fp_trace, "%s\n",&input_line);
    // -1 in type denotes #
    std::cout << input_line << '\n';
    std::string delimiter = ":";
    std::string address =  input_line.substr(0,input_line.find(delimiter));
    //std::string lnumber = rtoken.substr(0,rtoken.find(" "));
    //std::string number = rtoken.substr(0,rtoken.find(" "));
    std::cout << address << '\n';
    add1 = std::stoi(address);
    cache_vector.push_back(add1);
    //cache_vector.push_back(add2);
    std::cout << add1 << "\n";
    //printf("%d %d\n", add1, add2);
  }

  // need to take input from trace file and add that into a hashset
  // then based on config files, we need to have a cache vector(bcoz order is also important)
  // but also have a cache set to quickly check for hit or miss.
  //cache should of given size
  // each address will take word_size
  // block_size is used in mapping type
  //fclose(fp_trace);
  //fclose(fp_config);
  fclose(fp_output);
  return 0;
}
