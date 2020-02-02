void numintegration()
{ 

   float pi= 3.14159261;
   float b = pi/2;
   float a = 0;
   const  int N=50;
   //int n=50; //for the for loop
   float Integral = 0;
   float x[N],w[N],f[N];

    float dx = (b-a)/(N-1);


    TF1*function = new TF1("function","x",0,2*pi);

  

    for(int i=0;i<N;i++){
         

         x[i] = a + i*dx;


         //mid-point
         f[i] = function->Eval(x[i]+0.5*dx);
    
         Integral = Integral + f[i]*dx;


       }


    cout<<" The solution using mid-point evaluation is "<<Integral<<endl;
   // cout<<" The exact solution is "<<function->Integral(a,b);


          Integral =0;


       for (int i=0;i<N;i++){

       //Trapezoid

       	x[i] = a + i*dx;

       	if(i==0 || i==N)

       {	w[i] = 0.5*dx;

       	f[i] = function->Eval(x[i]);

       	Integral = Integral + f[i]*w[i];

       }

       else

       	{ w[i] = dx;


       	f[i] = function->Eval(x[i]);

       	Integral = Integral + f[i]*w[i];




       	}







       }            
          
       cout<<" The solution using Trapezoid rule is "<<Integral<<endl;
       cout<<"The exact solution is "<<function->Integral(a,b);   



    }





