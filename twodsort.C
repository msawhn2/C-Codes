void twodsort()
{int a[10]; int temp;
for (int i=0;i<10;i++)
{
  a[i] = 1+gRandom->Rndm()*10;
  cout<<a[i]<<" ";
}
cout<<endl;
for (i=0;i<9;i++)
{
  if(a[i]>a[i+1])
  {  temp = a[i];
     a[i]=a[i+1];
     a[i+1] =temp;
  }
  cout<<a[i]<<" ";
}
}