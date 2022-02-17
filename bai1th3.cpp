void trung_hau(list &l,char *chuoi)
{
	int n=strlen(chuoi);
	char hauto[50];int j=0;

	for(int i=0;i<n;i++)
	{
		char c=chuoi[i];

		if(isalnum(c)!=0)
		{
			hauto[j++]=c;
		}
		else
		{
			if(c=='(')
			{
				node *p=tao(c);
				add_dau(l,p);
			}
			else
			{
				if(c==')')
				{
					while(l.dau->info!='(')
					{
						node *p=l.dau;
						hauto[j++]=l.dau->info;
						l.dau=l.dau->next;
						delete p;
					}
					node *p=l.dau;
					l.dau=l.dau->next;
					delete p;
				}
				else
				{
					while(uu_tien(l.dau->info)>=uu_tien(c)&&l.dau!=NULL)///l?i
					{
						node *p=l.dau;
						hauto[j++]=l.dau->info;
						l.dau=l.dau->next;
						delete p;
					}
					node *p=tao(c);
					add_dau(l,p);	
				}
			}
		}
	}
	while(l.dau!=NULL)
	{
		node *p=l.dau;
		hauto[j++]=l.dau->info;
		l.dau=l.dau->next;
		delete p;
	}
	for(int i=0;i<j;i++)
	{
		printf("%c",hauto[i]);
	}
}
