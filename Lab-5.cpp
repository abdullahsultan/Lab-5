#include<iostream>
#include<string.h>
using namespace std;

class my_vector
{
public:
  my_vector() //Dfault constructor
  {}
  my_vector(int l) //constructor
  {length=l;a=nullptr;
  a=(int*)malloc(length*sizeof(int));
  }

  my_vector(my_vector & obj ) // Copy constructor
  {
     length = obj.length;
     memcpy(&a,&obj.a,sizeof(a));
  }

  ~my_vector() // Destructer
  {free(a) ;}


  bool redim(int l)
  {
    length=l;
    a=(int*)realloc(a,length); //Expanding Memory
    return true;
  }
  void operator =(my_vector & obj) //Overloading =
  {
    length=obj.length;
    int *temp; temp = new int;
    temp=obj.a;
    *a=*temp;
    delete temp;
  }

  int operator [] (int x) //overloading []
  {
  //  for(int i = 0; i < length; i++)
    //    cout<<a[i]<<" ";
    return a[x];
  }
  int size()
  {

    return length;
  }


  //my_vector operator <<()

void operator * (my_vector obj)    //Multiplying arrays
 {
   for(int x=0;x<length;x++)
   {
     a[x]=a[x]*obj.a[x];
   }

 }


 void operator * (int m) //Multiplying arrays with a constant
 {
   for (int l=0;l<length;l++)
   a[l]=a[l]*m;
 }

 void operator +(my_vector obj)
 {
   for (int l=0;l<length;l++)
   a[l]=a[l]+obj.a[l];
 }

//cin and cout functions
void inner()
 {
   int l;
   //x=a;
   cout<<"\n Enter values of vector \n";
   for(l=0;l<length;l++)
   {cin>>a[l];

   }
 }

void outer()
 {
   int l;
   //x=a;
   for(l=0;l<length;l++)
   {cout<<a[l];}

   cout<<"\n Length of vector is "<<length<<endl;
 }



private:
  int length;
  int *a;
};

int main(int argc, char const *argv[]) {
  int l;
  cout<<"Enter length of vector \n";
  cin>>l;
  my_vector v1(l);
  cout<<"\n Enter data of vector \n";
  v1.inner();
  my_vector v2(v1);
  cout<<"\n V1 \n";
  v1.outer();
  cout<<"\n V2 after copy constructor \n";
  v2.outer();
  cout<<"\n At 6rd of array \n";
  cout<<v1[6];
  v1*2;
  cout<<"\n v1 after * by a constant \n";
  v1.outer();
  v1*v2;
  cout<<"\n V1 *V2 \n";
  v1.outer();
  v1+v2;
  cout<<"\n V1+V2 \n";
  v1.outer();
  cout<<"Enter new dim of v1"<<endl;
  cin>>l;
  v1.redim(l);
  return 0;
}
