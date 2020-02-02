{
	double V[10][10][10];
	hist = new TH3D("hist","", 10., -1., 1., 10., -1., 1., 10., -1., 1.);
//Creating discretized space and setting all values to zero
	for (int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			for(int k=0; k<10; k++)
			{
				if(i == 4 && j == 4 && k == 4)
					{
						V[i][j][k] = 1;
					}
					else
					{
				V[i][j][k] = 0;
			}
			}
		}
	}
//create iterative updating process to implement relaxation method while maintaining boundary conditions
for(int n = 0; n<10000; n++)
{
	for (int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			for(int k=0; k<10; k++)
			{
				if(i==0 || j==0 || k==0 || i==9 || j==9|| k==9)
				{
					V[i][j][k]= 0;
				}
				else
				{
					if(i == 4 && j == 4 && k == 4)
					{
						V[i][j][k] = 1;
					}
					else
					{
					V[i][j][k] = (1./6.)*(V[i+1][j][k]+V[i-1][j][k]+V[i][j+1][k]+V[i][j-1][k]+V[i][j][k+1]+V[i][j][k-1]);
				}
				}

			}
		}
	}
}
for (int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			for(int k=0; k<10; k++)
			{
				hist->SetBinContent(i, j, k, V[i][j][k]);
				cout<<V[i][j][k]<<endl;
			}
		}
	}
	hist->Draw("LEGO2");
}