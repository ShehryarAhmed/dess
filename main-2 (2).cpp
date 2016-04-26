#include <iostream>
#include <string.h>
#include <cstdlib>
#include<fstream>
#include<sstream>
#include<bitset>
#include <math.h>
int dec_to_bin(int dec)
    {
    long rem,i=1,sum=0;
    do
    {
        rem=dec%2;
        sum=sum + (i*rem);
        dec=dec/2;
        i=i*10;
    }
    while(dec>0);
    return sum;
}

using namespace std;
int Bin_To_dec(int n)
{
int deciaml =0, i=0, rem;
while(n!=0)
    {
        rem = n%10;
        n/=10;
        deciaml+= rem*pow(2, i);
        ++i;
    }
return deciaml;
}
int perm[] = {16,7,20,21,
29,12,28,17,
1,15,23,26,
5,18,31,10,
2,8,24,14,
32,27,3,9,
19,13,30,6,
22,11,4,25};

int main()
{
    int j = 1;
    int K_pc1[56];
    int k_56[16][56];
    int k_48[16][48];
    int c[17][28];
    int d[17][28];
    int l[17][32];
    int r[17][32];
    ostringstream row[17][8];
    ostringstream colum[17][8];
    int sb[17][8];
    string tempprow[17][8],temppcol[17][8];
    int rowint , colint;
    int rows[17][8],cols[17][8];
    string temp_String[17][8];
    int ActualBit[17][32];
    char StringBits[17][32];
    int E_R[17][48];
    int k_er[17][48];
    int b[8][6];
    int fbit[17][32];
    int L16R16[64];
    int afteripinvers[64];

    int message[] = {0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,0,0,1,1,1,1,0,0,0,1,0,0,1,1,0,1,0,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,0,1,1,1,1};
    int K_orig[] = {0,0,0,1,0,0,1,1,0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1};
    int pc1[] = {
                57,49,41,33,25,17,9,
                1,58,50,42,34,26,18,
                10,2,59,51,43,35,27,
                19,11,3,60,52,44,36,
                63,55,47,39,31,23,15,
                7,62,54,46,38,30,22,
                14,6,61,53,45,37,29,
                21,13,5,28,20,12,4};
int pc2[] = {
                14,17,11,24,1,5,
                3,28,15,6,21,10,
                23,19,12,4,26,8,
                16,7,27,20,13,2,
                41,52,31,37,47,55,
                30,40,51,45,33,48,
                44,49,39,56,34,53,
                46,42,50,36,29,32};

int IP_message[] = {
                58,50,42,34,26,18,10,2,
                60,52,44,36,28,20,12,4,
                62,54,46,38,30,22,14,6,
                64,56,48,40,32,24,16,8,
                57,49,41,33,25,17,9,1,
                59,51,43,35,27,19,11,3,
                61,53,45,37,29,21,13,5,
                63,55,47,39,31,23,15,7};

int ipinvers[64] = {
                40,8,48,16,56,24,64,32,
                39,7,47,15,55,23,63,31,
                38,6,46,14,54,22,62,30,
                37,5,45,13,53,21,61,29,
                36,4,44,12,52,20,60,28,
                35,3,43,11,51,19,59,27,
                34,2,42,10,50,18,58,26,
                33,1,41,9,49,17,57,25};

int E[48] = {
                32,1,2,3,4,5,
                4,5,6,7,8,9,
                8,9,10,11,12,13,
                12,13,14,15,16,17,
                16,17,18,19,20,21,
                20,21,22,23,24,25,
                24,25,26,27,28,29,
                28,29,30,31,32,1};



    for (int i =0 ; i <= 63 ; i++)
    {
        K_pc1[i] = K_orig[pc1[i]-1];
    }

    ofstream outfile("keypc1.txt",ios::out);
    for(int i = 0 ; i < 56; i++){
      outfile << K_pc1[i];
    }
    outfile.close();


 for(int i = 0 ; i < 28 ;i++)
{
    c[0][i] = K_pc1[i];
    d[0][i] = K_pc1[i+28];

}
for (int j = 0; j<=15; j++)
{
 if (j==0 || j==1 || j==8 || j==15)
 {
    c[j+1][27] =c[j+0][0];
    d[j+1][27] =d[j+0][0];
    for(int i = 27 ; i >= 1; i--){
        c[j+1][i-1]=c[j+0][i] ;
        d[j+1][i-1]=d[j+0][i] ;
    }int k_48[16][48];

}
else
{
            c[j+1][26] =c[j+0][0];
            d[j+1][26] =d[j+0][0];

            c[j+1][27] =c[j+0][1];
            d[j+1][27] =d[j+0][1];

            for(int i = 27 ; i >= 2; i--){
                c[j+1][i-2]=c[j+0][i] ;
                d[j+1][i-2]=d[j+0][i] ;
    }
}
}
for (int j = 1 ; j < 17 ;j++)
{
cout << endl;
cout << "C" << j << " :";
for(int i = 0 ; i < 28 ;i++)
{
cout  << c[j][i];
}
cout << endl;
cout<< "D"<<j<< " :";
for(int i = 0 ; i < 28 ;i++)
{
cout  <<d[j][i];
}
}

for (int j = 1; j<=16 ; j++) {

for (int i = 0; i< 28; i++){
    k_56[j-1][i] = c[j][i];
    k_56[j-1][i+28] = d[j][i];

} }
 for (int j =0 ; j <= 15 ; j++) {
 for (int i =0 ; i <= 47 ; i++)
    {
        k_48[j][i] = k_56[j][pc2[i]-1];
    }
    }
for (int j =0 ; j <= 15 ; j++) {
   cout << endl << "key  :" << j << endl;
 for (int i =0 ; i <= 47 ; i++)
    {
        cout<<k_48[j][i];
    }
    }
    int m_IP[64];

 for (int i =0 ; i <= 63 ; i++)
    {
        m_IP[i] = message[IP_message[i]-1];
    }
    cout << endl<<"IP_message : "<<endl;
     for (int i =0 ; i <= 63 ; i++)
    {
       cout <<  m_IP[i];
    }


  for(int i = 0 ; i < 32 ;i++)
{
    l[0][i] = m_IP[i];
    r[0][i] = m_IP[i+32];

}
cout << endl << "L0 : ";
  for(int i = 0 ; i < 32 ;i++)
{
    cout << l[0][i];
}
cout << endl << "R0 : ";
  for(int i = 0 ; i < 32 ;i++)
{
    cout << r[0][i];
}
while(j<=16){
for (int i =0 ; i <= 47 ; i++)
    {
        E_R[j][i] = r[j-1][E[i]-1];//r1= L0 + f(Ro,k1)
    }

for (int i =0 ; i <= 47 ; i++)
    {
        k_er[j][i] = E_R[j][i] ^ k_48[j-1][i];
//        cout << k_er[i];
    }
for (int i =0; i<= 5 ; i++)
{
    b[0][i] = k_er[j][i];
    b[1][i] = k_er[j][i+6];
    b[2][i] = k_er[j][i+12];
    b[3][i] = k_er[j][i+18];
    b[4][i] = k_er[j][i+24];
    b[5][i] = k_er[j][i+30];
    b[6][i] = k_er[j][i+36];
    b[7][i] = k_er[j][i+42];
}
/////S1 blockistringstream iss(colum.str());
    int s1[4][16];
    int S_Temp[64]={14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13};
    for(int i =0 ; i < 16; i++){

    s1[0][i] = S_Temp[i];
    s1[1][i] = S_Temp[i+16];
    s1[2][i] = S_Temp[i+32];
    s1[3][i] = S_Temp[i+48];
            }
///s1;k_48
    int s2[4][16];
    int S_Temp2[64]={15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
                     3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
                     0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
                     13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9};
    for(int i =0 ; i < 16; i++){
    s2[0][i] = S_Temp2[i];
    s2[1][i] = S_Temp2[i+16];
    s2[2][i] = S_Temp2[i+32];
    s2[3][i] = S_Temp2[i+48];
            }
///s3
   int s3[4][16];
    int S_Temp3[64]={10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
                     13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
                     13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
                    1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12};

    for(int i =0 ; i < 16; i++){
    s3[0][i] = S_Temp3[i];
    s3[1][i] = S_Temp3[i+16];
    s3[2][i] = S_Temp3[i+32];
    s3[3][i] = S_Temp3[i+48];
            }
///s4
   int s4[4][16];
    int S_Temp4[64]={7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14};
    for(int i =0 ; i < 16; i++){

    s4[0][i] = S_Temp4[i];
    s4[1][i] = S_Temp4[i+16];
    s4[2][i] = S_Temp4[i+32];
    s4[3][i] = S_Temp4[i+48];
            }
///s5
   int s5[4][16];
    int S_Temp5[64]={2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3};
    for(int i =0 ; i < 16; i++){

    s5[0][i] = S_Temp5[i];
    s5[1][i] = S_Temp5[i+16];
    s5[2][i] = S_Temp5[i+32];
    s5[3][i] = S_Temp5[i+48];
            }

///s6
   int s6[4][16];
    int S_Temp6[64]={12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13};
    for(int i =0 ; i < 16; i++){

    s6[0][i] = S_Temp6[i];
    s6[1][i] = S_Temp6[i+16];
    s6[2][i] = S_Temp6[i+32];
    s6[3][i] = S_Temp6[i+48];
    }
///s7
   int s7[4][16];
    int S_Temp7[64]={4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12};
    for(int i =0 ; i < 16; i++){

    s7[0][i] = S_Temp7[i];
    s7[1][i] = S_Temp7[i+16];
    s7[2][i] = S_Temp7[i+32];
    s7[3][i] = S_Temp7[i+48];
    }
    ///s8
   int s8[4][16];
    int S_Temp8[64]={13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11};
    for(int i =0 ; i < 16; i++){

    s8[0][i] = S_Temp8[i];
    s8[1][i] = S_Temp8[i+16];
    s8[2][i] = S_Temp8[i+32];
    s8[3][i] = S_Temp8[i+48];
    }

for(int i =0 ;i<8; i++){
row[j][i]<<b[i][0]<<b[i][5];
colum[j][i]<<b[i][1]<< b[i][2] << b[i][3] << b[i][4];
istringstream iss(colum[j][i].str());
istringstream iss1(row[j][i].str());
iss>>temppcol[j][i];
iss1>>tempprow[j][i];
}
for(int i = 0; i < 8; i++){
stringstream convert(tempprow[j][i]);
convert>>rowint;
stringstream convertcl(temppcol[j][i]);
convertcl>>colint;
 rows[j][i] = Bin_To_dec(rowint);
 cols[j][i] = Bin_To_dec(colint);
}

sb[j][0] = s1[rows[j][0]][cols[j][0]];
sb[j][1] = s2[rows[j][1]][cols[j][1]];
sb[j][2] = s3[rows[j][2]][cols[j][2]];
sb[j][3] = s4[rows[j][3]][cols[j][3]];
sb[j][4] = s5[rows[j][4]][cols[j][4]];
sb[j][5] = s6[rows[j][5]][cols[j][5]];
sb[j][6] = s7[rows[j][6]][cols[j][6]];
sb[j][7] = s8[rows[j][7]][cols[j][7]];


for(int i = 0; i < 8; i++){
bitset<4> my4Bits[i];
my4Bits[i]=sb[j][i];
temp_String[j][i] =my4Bits[i].to_string();
///yeha pe hamare pas values String array me save ho rhi hai.
}
///yeha pe hum String type ke zariye print krwa rhe hai.
string data = temp_String[j][0]+temp_String[j][1]+temp_String[j][2]+temp_String[j][3]+temp_String[j][4]+temp_String[j][5]+temp_String[j][6]+temp_String[j][7];
///cout << data << endl;       ///yeha pe hamara sb[] ka jo array hai usko humne string me convert kr diya hai.
for(int i=0; i<32; i++)
    {
       StringBits[j][i] = data[i];     ///yeha pe hum ne data joke string me tha us ko humne char ke array me / kr diya hai,
    }
cout << endl;
for(int i=0; i<32; i++)
    {
     ActualBit[j][i]= StringBits[j][i];    ///yeha pe hum ne cahr ko int me convert kr diya hai, but ab jo hamare pas value a rhi hai wo ASCII code me a rgi hai, to ab hum esko ascii se int me convert krenge. kr diya hai,
    if(ActualBit[j][i]==48)
        {
            ActualBit[j][i]=0;
        }
    else
        {
            ActualBit[j][i]=1;
        }}
for (int i =0 ; i <= 63 ; i++)
    {
        fbit[j][i] = ActualBit[j][perm[i]-1];         ///yeha pe hamare pas function ka answer a rha hai joke pdf se similar hai,
    }

cout<<endl << endl << "L"<<j<<" : ";
  for(int i = 0 ; i < 32 ;i++)
{
    l[j][i] = r[j-1][i];
    cout << l[j][i];
}
cout << endl << "R"<<j<<" : ";
for(int i=0;i<32;i++)
    {
        r[j][i] = l[j-1][i] ^ fbit[j][i];
        cout << r[j][i];
    }
    j++;
}
for(int i=0;i<32;i++)
{
    L16R16[i] = r[16][i];
    L16R16[i+32] = l[16][i];
}
cout<<endl<<"R16L16 : "<<endl;
for(int i=0;i<64;i++)
{
    cout <<L16R16[i];
}
cout<<endl<<"IP_Inverse : "<<endl;
for(int i = 0 ; i <64; i++){
afteripinvers[i] = L16R16[ipinvers[i]-1];
cout << afteripinvers[i];
}
}
