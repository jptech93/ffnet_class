#define PRINT() for(int i=0;i<bp.no_of_hidden+1;i++){cout<<"\nLayer "<<i<<" :\n";for(int j=0;j<bp.neurons_in_layer[i];j++){				cout<<"\nNeuron "<<j<<" :\n";for(int k=0;k<bp.nnet[i][j].no_of_inputs;k++)cout<<"Weight: "<<bp.nnet[i][j](k)<<"  Input: "<<bp.nnet[i][j][k]<<"\t";		cout<<"Bias: "<<bp.nnet[i][j](bp.nnet[i][j].no_of_inputs)<<" With const input: "<<bp.nnet[i][j][bp.nnet[i][j].no_of_inputs]<<"\n";				cout<<"Output: "<<bp.nnet[i][j].out();	cout<<"\n";	}}
		

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
	backpropagation bp(5,1,1,&(x), activation,rnd,lr,.2);
	float input[5],output;
	
	
	/* TRAINING 
	for(int k=0;k<1000000;k++)
		for(int j=-205;j<525;j++){
			for(int i=0;i<5;i++)
				input[i]=sin(float(i+j))*sin(float(i+j));
			output=sin(float(5+j))*sin(float(5+j));
			bp.backpropagate(input,&output);
			//cout<<"\n\n\n";
			//PRINT()
			bp.update_weights();
	
			//cout<<"\n"<<(output[1]>.5?"-":"+")<<output[0]<<"\t"<<(bp.actual_outputs[1]>.5?"-":"+")<<bp.actual_outputs[0];
		}
	bp.write_to_file("weights.txt");
	*/
	
	bp.nnet.read_from_file("weights.txt");
	float temp1,temp2;
	temp1=sin(1010.00)*sin(1010.00);
	temp2=sin(107.00)*sin(107.00);
	cout<<"\n"<<temp1<<"\t"<<temp2;
	for(int i=0;i<5;i++)
			input[i]=sin(float(i+1005))*sin(float(i+1005));
	bp.nnet.set_inputs(input);
	bp.nnet.calc_output(&output);
	//PRINT()
	cout<<"\n"<<output;
	for(int i=0;i<5;i++)
			input[i]=sin(float(i+102))*sin(float(i+102));
	bp.nnet.set_inputs(input);
	bp.nnet.calc_output(&output);
	//PRINT()
	cout<<"\t"<<output<<"\n";
	
}
