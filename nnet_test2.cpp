
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<iostream>
#include "backpropagation"

using namespace std;

inline float backpropagation::df_activation(int layer,int neuron){
	return (nnet[layer][neuron].out()*(1-nnet[layer][neuron].out()));
}

inline int random(int lowest,int highest){
	
    //srand((unsigned)time(0)); 
    int rnd=rand()%10;
    if (rnd>3)
    	srand(rand()*rand()*time(0));
    int random_integer; 
    int range=(highest-lowest)+1; 
    //for(int index=0; index<20; index++)
    //random_integer = lowest+int(range*rand()/(RAND_MAX + 1.0)); 
    random_integer=lowest+(rand()%(range));
    return random_integer;
}

void rnd(float *f){
	*f=random(-1,1);
}

float activation(float f){
	float act=(1.0/(1.0+exp(-f)));
	return act;
}

int main(){
	srand(rand()*rand()*time(0));
	int x;
	x=6;
	float lr[2];
	lr[0]=.2;
	lr[1]=.1;
	ffnet nnet(5,1,1,&(x), activation,rnd);
	float input[5],output;
	int t,n1;
	cout<<"Enter Starting T\n";
	cin>>t;
	cout<<"Enter numbers to find values upto..\n";
	cin>>n1;
	
	nnet.read_from_file("weights.txt");
	
	fstream fr;
	fr.open("abc.txt",ios::out | ios::trunc);
	fr<<"X\tY\n";
	for(int i=0;i<5;i++)
		input[i]=sin(float(t+i))*sin(float(t+i));
	
	for(int j=t;j<n1-5;j++){
		
		nnet.set_inputs(input);
		nnet.calc_output(&output);
		
		fr<<(j+5)<<"\t"<<(sin(float(j+5))*sin(float(j+5)))<<"\n";
		//fr<<(j+5)<<"\t"<<output<<"\n";
	
		for(int i=1;i<5;i++)
			input[i-1]=input[i];
		input[4]=output;
		
	}
	
}
