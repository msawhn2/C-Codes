void twoarrayreverse()
{int AA[3][5];
for(int j=0;j<3;j++)
{ for(int i=4;i>=0;i--)
{ AA[j][i]= 1+i+5*j;
cout<<AA[j][i]<<" ";
}
cout<<endl;
}
}