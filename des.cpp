#include<stdio.h>
#include<malloc.h>
int parity_bit[]={57,49,41,33,25,17,9,1,
					58,50,42,34,26,18,10,2,
					59,51,43,35,27,19,11,3,
					60,52,44,36,63,55,47,39,
					31,23,15,7,62,54,46,38,
					30,22,14,6,61,53,45,37,
					29,21,13,5,28,20,12,4};
int bit_shifts[]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
int compression[]={14,17,11,24,1,5,3,28,
	15,6,21,10,23,19,12,4,
	26,8,16,7,27,20,13,2,
	41,52,31,37,47,55,30,40,
	51,45,33,48,44,49,39,56,
	34,53,46,42,50,36,29,32};
int ip[]={
58, 50, 42, 34, 26, 18, 10, 02,
60, 52, 44, 36, 28, 20, 12, 04,
62, 54, 46, 38, 30, 22, 14, 06,
64, 56, 48, 40, 32, 24, 16, 8,
57, 49, 41, 33, 25, 17, 9, 01,
59, 51, 43, 35, 27, 19, 11, 03,
61, 53, 45, 37, 29, 21, 13, 05,
63, 55, 47, 39, 31, 23, 15, 07
};
int exp_d_box[]={
32,1,2,3,4,5,
4,5,6,7,8,9,
8,9,10,11,12,13,
12,13,14,15,16,17,
16,17,18,19,20,21,
20,21,22,23,24,25,
24,25,26,27,28,29,
28,29,30,31,32,1
};

int DesSbox[8][4][16] = {
 
   {
	   {14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7},
	   { 0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8},
	   { 4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0},
	   {15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13},
   },
 
   {
	   {15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10},
	   { 3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5},
	   { 0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15},
	   {13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9},
   },
 
   {
	   {10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8},
	   {13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1},
	   {13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7},
	   { 1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12},
   },
 
   {
	   { 7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15},
	   {13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9},
	   {10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4},
	   { 3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14},
   },
 
   {
	   { 2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9},
	   {14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6},
	   { 4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14},
	   {11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3},
   },
 
   {
	   {12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11},
	   {10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8},
	   { 9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6},
	   { 4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13},
   },
 
   {
	   { 4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1},
	   {13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6},
	   { 1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2},
	   { 6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12},
   },
 
   {
	   {13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7},
	   { 1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2},
	   { 7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8},
	   { 2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11},
   },
 
};
int start_d_block[]={
16,7,20,21,29,12,28,17,
1,15,23,26,5,18,31,10,
2,8,24,14,32,27,3,9,
19,13,30,6,22,11,4,25
};
int final_per[]={
40,8,48,16,56,24,64,32,
39,7,47,15,55,23,63,31,
38,6,46,14,54,22,62,30,
37,5,45,13,53,21,61,29,
36,4,44,12,52,20,60,28,
35,3,43,11,51,19,59,27,
34,2,42,10,50,18,58,26,
33,1,41,9,49,17,57,25
};
int *after_f_xor(int *f_out,int *l_data){
	int *ans=(int*)malloc(sizeof(int)*32);
	for(int i=0;i<32;i++){
		ans[i]=(f_out[i]==l_data[i])?0:1;
	}
	return ans;
}
int *exp_d_block_fun(int *arr){
	int *res=(int*)malloc(sizeof(int)*48);
	for(int i=0;i<48;i++){
		res[i]=arr[exp_d_box[i]-1];
		//printf("%d$",exp_d_box[i]-1);
	}
	return res;
}
int *fn_xor(int *arr,int *key){
	for(int i=0;i<48;i++){
		arr[i]=(arr[i]==key[i])?0:1;
	}
	return arr;
}
void shifting(int *arr,int round){
	if(bit_shifts[round]==1){
		int temp=arr[0];
		for(int i=0;i<27;i++){
			arr[i]=arr[i+1];
		}
		arr[27]=temp;
	}else if(bit_shifts[round]==2){
		int temp=arr[0],temp2=arr[1];
		for(int i=0;i<26;i++){
			arr[i]=arr[i+2];
		}
		arr[26]=temp;
		arr[27]=temp2;
	}
}
int *parity_bit_fun(int *input_64){
	int *res=(int*)malloc(sizeof(int)*56);
	for(int i=0;i<56;i++){
			res[i]=input_64[parity_bit[i]-1];
	}
	return res;
}
int *getkey(int *left){
	int *res=(int*)malloc(sizeof(int)*48);
	for(int i=0;i<48;i++){
		res[i]=left[compression[i]-1];
	}
	return res;
}
int fun(int *a, int i) {
	int row = a[0]*2 + a[5];
	int col = a[1]*8 + a[2]*4 + a[3]*2 + a[4];
	return DesSbox[i][row][col];
}

int *print_bin(char *hexa,int n){
	int *bin=(int *)malloc(sizeof(int)*n*4);
	int i=0,j=0;
	while (hexa[i]){

        	switch (hexa[i])

        	{

			case '0':

			    //printf("0000");
				bin[j++]=0;bin[j++]=0;bin[j++]=0;bin[j++]=0;
				 break;

			case '1':

			    //printf("0001");
				bin[j++]=0;bin[j++]=0;bin[j++]=0;bin[j++]=1; break;

			case '2':

			    //printf("0010"); 
				bin[j++]=0;bin[j++]=0;bin[j++]=1;bin[j++]=0;break;

			case '3':

			   // printf("0011");
				bin[j++]=0;bin[j++]=0;bin[j++]=1;bin[j++]=1;break;

			case '4':

			    //printf("0100");
				bin[j++]=0;bin[j++]=1;bin[j++]=0;bin[j++]=0;break;
			case '5':

			   // printf("0101");
				bin[j++]=0;bin[j++]=1;bin[j++]=0;bin[j++]=1;break;

			case '6':

			    //printf("0110");
				bin[j++]=0;bin[j++]=1;bin[j++]=1;bin[j++]=0;break;

			case '7':

			    //printf("0111");
				bin[j++]=0;bin[j++]=1;bin[j++]=1;bin[j++]=1;break;
			case '8':

			    //printf("1000");
				bin[j++]=1;bin[j++]=0;bin[j++]=0;bin[j++]=0;break;

			case '9':

			    //printf("1001");
				bin[j++]=1;bin[j++]=0;bin[j++]=0;bin[j++]=1;break;
			case 'A':
			case 'a':

			    //printf("1010");
				bin[j++]=1;bin[j++]=0;bin[j++]=1;bin[j++]=0;break;

			case 'B':
			case 'b':
			    //printf("1011");
				bin[j++]=1;bin[j++]=0;bin[j++]=1;bin[j++]=1;break;

			case 'C':
			case 'c':
			    //printf("1100");
				bin[j++]=1;bin[j++]=1;bin[j++]=0;bin[j++]=0;break;

			case 'D':
			case 'd':
			    //printf("1101");
				bin[j++]=1;bin[j++]=1;bin[j++]=0;bin[j++]=1;break;
			case 'E':
			case 'e':
			    //printf("1110");
				bin[j++]=1;bin[j++]=1;bin[j++]=1;bin[j++]=0;break;

			case 'F':
			case 'f':
			    //printf("1111");
				bin[j++]=1;bin[j++]=1;bin[j++]=1;bin[j++]=1;break;

			default:

			    printf("\n Invalid hexa digit %c ", hexa[i]);

		}

		i++;
    	}
	return bin;
}
void print_hex(int *arr,int n){
	for(int i=0;i<n;i=i+4){
		if(arr[i]==0&&arr[i+1]==0&&arr[i+2]==0&&arr[i+3]==0){
			printf("0");
		}else if(arr[i]==0&&arr[i+1]==0&&arr[i+2]==0&&arr[i+3]==1){
			printf("1");
		}else if(arr[i]==0&&arr[i+1]==0&&arr[i+2]==1&&arr[i+3]==0){
			printf("2");
		}else if(arr[i]==0&&arr[i+1]==0&&arr[i+2]==1&&arr[i+3]==1){
			printf("3");
		}else if(arr[i]==0&&arr[i+1]==1&&arr[i+2]==0&&arr[i+3]==0){
			printf("4");
		}else if(arr[i]==0&&arr[i+1]==1&&arr[i+2]==0&&arr[i+3]==1){
			printf("5");
		}else if(arr[i]==0&&arr[i+1]==1&&arr[i+2]==1&&arr[i+3]==0){
			printf("6");
		}else if(arr[i]==0&&arr[i+1]==1&&arr[i+2]==1&&arr[i+3]==1){
			printf("7");
		}else if(arr[i]==1&&arr[i+1]==0&&arr[i+2]==0&&arr[i+3]==0){
			printf("8");
		}else if(arr[i]==1&&arr[i+1]==0&&arr[i+2]==0&&arr[i+3]==1){
			printf("9");
		}else if(arr[i]==1&&arr[i+1]==0&&arr[i+2]==1&&arr[i+3]==0){
			printf("A");
		}else if(arr[i]==1&&arr[i+1]==0&&arr[i+2]==1&&arr[i+3]==1){
			printf("B");
		}else if(arr[i]==1&&arr[i+1]==1&&arr[i+2]==0&&arr[i+3]==0){
			printf("C");
		}else if(arr[i]==1&&arr[i+1]==1&&arr[i+2]==0&&arr[i+3]==1){
			printf("D");
		}else if(arr[i]==1&&arr[i+1]==1&&arr[i+2]==1&&arr[i+3]==0){
			printf("E");
		}else if(arr[i]==1&&arr[i+1]==1&&arr[i+2]==1&&arr[i+3]==1){
			printf("F");
		}
	}
	//printf("\n");
}
int *s_box_fun(int *arr){
	int j = 0;
	int *update_input = (int*)malloc(sizeof(int)*32);
	//print_hex(arr,48);
	for(int i=0; i<48; i+=6){
		int temp = fun(&arr[i], i/6);
		//printf("%d-",temp);
		update_input[j] = temp/8;
		temp -= (update_input[j]*8);
		j++;
		update_input[j] = temp/4;
		temp -= (update_input[j]*4);
		j++;
		update_input[j] = temp/2;
		temp -= (update_input[j]*2);
		j++;
		update_input[j] = temp;
		j++;
	}
	return update_input;
}
int *ip_fun(int *arr){
	int *ans=(int*)malloc(sizeof(int)*64);
	for(int i=0;i<64;i++){
		ans[i]=arr[ip[i]-1];	
	}
	return ans;
}
int *f(int *arr,int *key){
	//printf("d-block\n");
	for(int i=0;i<32;i++){
		//printf("%d-",arr[i]);
	}
	//printf("d-block\n");
	int *a1=exp_d_block_fun(arr);
	a1=fn_xor(a1,key);
	//printf("E-block\n");
	for(int i=0;i<48;i++){
		//printf("%d-",a1[i]);
	}
	//printf("E-block\n");
	arr=s_box_fun(a1);
	//printf("S-block\n");
	for(int i=0;i<32;i++){
		//printf("%d-",arr[i]);
	}
	//printf("S-block\n");
	int *a2=(int *)malloc(sizeof(int)*32);
	for(int i=0;i<32;i++){
		a2[i]=arr[start_d_block[i]-1];
		//printf("%d#",start_d_block[i]);
	}
	return a2;
}
void swap(int *a,int *b){
	int *temp=a;
	a=b;
	b=a;
}
int *final_per_f(int *arr){
	int *ans=(int*)malloc(sizeof(int)*64);
	for(int i=0;i<64;i++){
		ans[i]=arr[final_per[i]-1];
	}
	return ans;
}
int main(){
	//int arr[]={0,0,0,1,0,0,1,1,0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1};
	//int arr[]={1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1};
	char *key_str="AABB09182736CCDD";
	int *bin_key=print_bin(key_str,16);
	char *data_str="123456ABCD132536";
	printf("---------------------ENCRIPTION----------------------------\n");
	int *bin_data=ip_fun(print_bin(data_str,16));
	printf("Plaintext: %s\n",data_str);
	printf("After initial permutation :");
	print_hex(bin_data,64);
	printf("\n");
	int *data_left=bin_data;
	int *data_right=&bin_data[32];
	int *key=parity_bit_fun(bin_key);
	int *o_key=key;
	int *k_left=key,*k_right=&key[28];
	int *stack_keys[16];
	printf("Round\t\tLeft\t\tRight\t\tRound key\n");
	for(int i=0;i<16;i++){
		shifting(k_left,i);
		shifting(k_right,i);
		key=getkey(k_left);
		//printf("_________________\n");
		//print_hex(key,48);	
		//printf("__________________\n");
		int *f_out =f(data_right,key);
	
	
		int *data_left_p=data_left;
		data_left=data_right;
		data_right=after_f_xor(f_out,data_left_p);
		printf("Round %2d\t",i+1);
		print_hex(data_left,32);
		printf("\t");
		print_hex(data_right,32);
		printf("\t");
		print_hex(key,48);
		stack_keys[i]=key;
		printf("\n");
	}
	//swap(data_left,data_right);
	int *combine=(int*)malloc(sizeof(int)*64);
	for(int i=0;i<32;i++){
		combine[i]=data_right[i];
	}
	for(int i=32;i<64;i++){
		combine[i]=data_left[i-32];
	}
	printf("After combination: ");
	print_hex(combine,64);
	printf("\n");
	int *enc_text=final_per_f(combine);
	printf("Ciphertext: ");
	print_hex(enc_text,64);
	printf("\n");
	/*printf("---------------------DECRIPTION----------------------------\n");
	bin_data=ip_fun(enc_text);
	printf("Plaintext: ");
	print_hex(enc_text,64);
	printf("\n");
	printf("After initial permutation :");
	print_hex(bin_data,64);
	printf("\n");
	data_left=enc_text;data_right=&enc_text[32];
	printf("Round\t\tLeft\t\tRight\t\tRound key\n");
	for(int i=15;i>=0;i--){
		//printf("_________________\n");
		//print_hex(key,48);	
		//printf("__________________\n");
		int *f_out =f(data_right,stack_keys[i]);
	
	
		int *data_left_p=data_left;
		data_left=data_right;
		data_right=after_f_xor(f_out,data_left_p);
		printf("Round %2d\t",16-i);
		print_hex(data_left,32);
		printf("\t");
		print_hex(data_right,32);
		printf("\t");
		print_hex(stack_keys[i],48);
		printf("\n");
	}
	for(int i=0;i<32;i++){
		combine[i]=data_right[i];
	}
	for(int i=32;i<64;i++){
		combine[i]=data_left[i-32];
	}
	printf("After combination: ");
	print_hex(combine,64);
	printf("\n");
	int *plain_text=final_per_f(combine);
	printf("Ciphertext: ");
	print_hex(plain_text,64);
	printf("\n");*/
	return 0;
}

