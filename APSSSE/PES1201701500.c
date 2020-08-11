#include "intal.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

char* intal_add(const char* intal1, const char* intal2)
{
	int intal1_len = strlen(intal1);
	int intal2_len = strlen(intal2);
	if(intal1_len == 0 || intal2_len == 0)
		return NULL;
	//int larger,smaller;
	//char* result = (char*)malloc(sizeof(char) * 1000);
	//int result_len = 1000;
	int temp;
	int carry = 0;
	if(intal1_len > intal2_len)
	{
		char* result = (char*)malloc(sizeof(char) * (intal1_len + 1));
		result[intal1_len] = '\0';
		while(--intal2_len >= 0)
		{
			temp = carry + (intal1[--intal1_len] - '0') + (intal2[intal2_len] - '0');
			if(temp >= 10)
			{
				carry = 1;
				result[intal1_len] = '0' + (temp - 10);
			}
			else
			{
				carry = 0;
				result[intal1_len] = '0' + temp;
			}
			
		}
		while(intal1_len >= 1)
		{
			if(carry)
			{
				temp = carry + (intal1[--intal1_len] - '0');
				if(temp >= 10)
				{
					carry = 1;
					result[intal1_len] = '0' + (temp - 10);
				}
				else
				{
					carry = 0;
					result[intal1_len] = '0' + temp;
				}
			}
			else
			{
				--intal1_len;
				result[intal1_len] = intal1[intal1_len];
			}
		}
		
		if(carry == 1)
		{
			int result_len = strlen(result);
			char * final = (char*)malloc(sizeof(char) * (result_len + 2));
			//printf("final here\n");
			final[0] = '1';
			for(int i = 0;i < result_len + 1;i++)
			{
				//printf("here\n");
				final[i + 1] = result[i];
			}
			final[result_len + 1] = '\0';
			//strcat(final,result);
			free(result);
			return final;
		}
		else
		{
			
			return result;
		}
		
		
		
	}
	else
	{
		//printf("here %d\n",intal2_len);
		char* result = (char*)malloc(sizeof(char) * (intal2_len + 1));
		result[intal2_len] = '\0';
		while(--intal1_len >= 0)
		{
			temp = carry + (intal1[intal1_len] - '0') + (intal2[--intal2_len] - '0');
			if(temp >= 10)
			{
				carry = 1;
				result[intal2_len] = '0' + (temp - 10);
			}
			else
			{
				carry = 0;
				result[intal2_len] = '0' + temp;
			}
		}
		//printf("outside first while\n");
		while(intal2_len >= 1)
		{
			if(carry)
			{
				temp = carry + (intal2[--intal2_len] - '0');
				if(temp >= 10)
				{
					carry = 1;
					result[intal2_len] = '0' + (temp - 10);
				}
				else
				{
					carry = 0;
					result[intal2_len] = '0' + temp;
				}
			}
			else
			{
				--intal2_len;
				result[intal2_len] = intal2[intal2_len];
			}
		
		
				
		}
		//printf("outside second while\n");
		
		
		if(carry == 1)
		{
			//printf("str
			int result_len = strlen(result);
			char* final = (char*)malloc(sizeof(char) * (result_len + 2));
			final[0] = '1';
			for(int i = 0;i < result_len + 1;i++)
			{
				//printf("here\n");
				final[i + 1] = result[i];
			}
			final[result_len + 1] = '\0';
			//strcat(final,result);
			free(result);
			return final;
		}
		else
		{
			return result;
		}
		
		
		
	}
}

int intal_compare(const char* intal1, const char* intal2)
{
	int intal1_len = strlen(intal1);
	int intal2_len = strlen(intal2);
	//printf("%d %d\n",intal1_len,intal2_len);
	if(intal1_len > intal2_len)
	{
		return 1;
	}
	else if(intal2_len > intal1_len)
	{
		return -1;
	}
	else
	{
		int i = 0;
		while(i < intal1_len && intal1[i] == intal2[i])
		{
			i++;
		}
		if(i == intal1_len)
		{
			return 0;
		}
		if(intal1[i] - '0' > intal2[i] - '0')
		{
			return 1;
		}
		return -1;
	}
		
		
}

char* intal_diff(const char* intal1, const char* intal2)
{
	int intal1_len = strlen(intal1);
	int intal2_len = strlen(intal2);
	if(intal1_len == 0 || intal2_len == 0)
		return NULL;
	int temp,borrow = 0,i;
	//int result_len;
	char* result,*final;
	int cmp = intal_compare(intal1,intal2);
	//printf("%d\n",cmp);
	switch(cmp)
	{
		case 1 :
			result = (char*)malloc(sizeof(char) * (intal1_len + 1));
			result[intal1_len] = '\0';
			//printf("here ah?\n");
			while(--intal2_len >= 0)
			{
				temp = (intal1[--intal1_len] - '0') - (intal2[intal2_len] - '0') - borrow;
				if(temp < 0)
				{
					borrow = 1;
					result[intal1_len] = '0' + (temp + 10);
				}
				else
				{
					borrow = 0;
					result[intal1_len] = '0' + temp;
				}
			}
			while(intal1_len > 0)
			{
				--intal1_len;
				if(borrow)
				{
					temp = (intal1[intal1_len] - '0') - borrow;
					if(temp < 0)
					{
						borrow = 1;
						result[intal1_len]  =  '0' + (temp + 10);
					}
					else
					{
						borrow = 0;
						result[intal1_len]  =  '0' + (temp);
					}	
				}
				else
				{
					result[intal1_len] = intal1[intal1_len];
				}
			}
			i = 0;
			while(result[i] == '0')
			{
				i++;
			}
			if(i == 0)
				return result;
			//result_len = strlen(result);
			//final = (char*)malloc(sizeof(char) * (result_len - i));
			//strcpy(final,result + i);
			final = strdup(result + i);
			free(result);
			return final;
			
			break;
		case -1 :
			result = (char*)malloc(sizeof(char) * (intal2_len + 1));
			result[intal2_len] = '\0';
			while(--intal1_len >= 0)
			{
				temp = (intal2[--intal2_len] - '0') - (intal1[intal1_len] - '0') - borrow;
				//printf("temp:%d\n",temp);
				if(temp < 0)
				{
					borrow = 1;
					result[intal2_len] = '0' + (temp + 10);
				}
				else
				{
					borrow = 0;
					result[intal2_len] = '0' + (temp);
				}
			}
			while(intal2_len > 0)
			{
				--intal2_len;
				if(borrow)
				{
					temp =  (intal2[intal2_len] - '0') - borrow;
					if(temp < 0)
					{
						borrow = 1;
						result[intal2_len]  =  '0' + (temp + 10);
					}
					else
					{
						borrow = 0;
						result[intal2_len]  =  '0' + (temp);
					}	
				}
				else
				{
					result[intal2_len] = intal2[intal2_len];
				}
			}
			//printf("out of first while\n");
			i = 0;
			while(result[i] == '0')
			{
				i++;
			}
			//printf("%s\n",result);
			//result_len = strlen(result);
			//final = (char*)malloc(sizeof(char) * (result_len - i));
			//strcpy(final,result + i);
			char* final = strdup(result + i);
			free(result);
			return final;
			
			break;
		default:
			result = (char*)malloc(sizeof(char) * (2));
			result[0] = '0';
			result[1] = '\0';
			return result;
	}
			
			
				
}

char* intal_multiply(const char* intal1, const char* intal2)
{
	int intal1_len = strlen(intal1);
	int intal2_len = strlen(intal2);
	if(intal1_len == 0 || intal2_len == 0)
		return NULL;
	int temp;
	int carry = 0;
	int result[intal1_len + intal2_len];
	if(!intal_compare(intal1,"0") || !intal_compare(intal2,"0"))
	{
		char* final = (char*) malloc(sizeof(char) * (2));
		final[0] = '0';
		final[1] = '\0';
		return final;
	}
	
	for(int i = 0;i < intal1_len + intal2_len;i++)
	{
		result[i] = 0;
		//carry[i] = 0;
	}
	
	for(int i = intal1_len - 1 ;i >= 0;i--)//25//1//0
	{
		for(int j = intal2_len - 1 ;j >= 0;j--)//7//0//0
		{
			temp = (result[i + j + 1]) + ((intal1[i] - '0') * (intal2[j] - '0'));
			//carry = 0;
			if(temp >= 10)
			{
				result[i + j + 1] = (temp % 10);//5//2//1
				carry = temp / 10;//3
			}
			else
			{
				result[i + j + 1] = temp;
				carry = 0;
			}
			if(carry > 0)
			{
				result[i + j] += carry;
			}
		}
		
	}
	int i = 0;
	while(result[i] == 0)
	{
		i++;
	}
	char* final = (char*) malloc(sizeof(char) * (intal1_len + intal2_len + 1 - i));
	int j;
	for(j = i;j < intal1_len + intal2_len;j++)
	{
		final[j - i] = '0' + result[j];
	}
	final[j - i] = '\0';
	
	return final;
}

char* intal_mod(const char* intal1, const char* intal2)
{
	int intal1_len = strlen(intal1);
	int intal2_len = strlen(intal2);
	if(intal1_len == 0 || intal2_len == 0)
		return NULL;
	char* zero = (char*) malloc(sizeof(char)*2);
	zero[0] = '0';
	zero[1] = '\0';
	if(!intal_compare(intal2,zero))
	{
		char* final = (char*) malloc(sizeof(char) * (1));
		final[0] = '\0';
		return final;
	}
	free(zero);
	//printf("%s %s\n",intal1,intal2);
	int cmp = intal_compare(intal1,intal2);
	if(cmp == -1)
	{
		char* final  = (char*)malloc(sizeof(char)*strlen(intal1) + 1);
		final[strlen(intal1)] = '\0';
		strcpy(final,intal1);
		return final;
	}
	char* double_intal2 = intal_add(intal2,intal2);
	char* result = intal_mod(intal1,double_intal2);
	free(double_intal2);
	//printf("check: %s %s %ld %ld\n",result,intal2,strlen(result),strlen(intal2));
	if(intal_compare(result,intal2) >= 0)
	{
		//printf("am i here\n");
		//free(result);
		char* old_result_free = strdup(result);
		free(result);
		result = intal_diff(old_result_free,intal2);
		free(old_result_free);
	}
	//printf("%s %s %s\n",result,intal1,intal2); 
	return result;
}

char* intal_pow(const char* intal1, unsigned int n)
{
	int intal1_len = strlen(intal1);
	if(intal1_len == 0)
		return NULL;
	
	if(n == 0)
	{
		char* final  = (char*)malloc(sizeof(char)*(2));
		final[0] = '1';
		final[1] = '\0';
		return final;
	}
	if(intal_compare(intal1,"0") == 0)
	{
		char* final  = (char*)malloc(sizeof(char)*(2));
		final[0] = '0';
		final[1] = '\0';
		return final;
	}
	char* res = (char*)malloc(sizeof(char)*1001);
	res[0] = '1';
	res[1] = '\0';
	char* base  = (char*)malloc(sizeof(char)*1001);
	strcpy(base,intal1);
	//printf("%s\n",base);
    while (n > 0)
	{ 
        if (n & 1)
		{
			//printf("here\n");
			char* temp = res;
            res = intal_multiply(res,base);
			free(temp);
			//printf("hell\n");
		}
		//printf("%s\n",res);
        n = n >> 1;
		char* old_base = base;
        base = intal_multiply(old_base,old_base);
		free(old_base);
    }
	free(base);
    return res;
}

char* intal_gcd(const char* intal1, const char* intal2)
{
	if(!intal_compare(intal1,"0") && !intal_compare(intal2,"0"))
	{
		char* final  = (char*)malloc(sizeof(char)*(2));
		final[0] = '0';
		final[1] = '\0';
		return final;
	}
	if(!intal_compare(intal2,"0"))
	{
		char* final  = (char*)malloc(sizeof(char)*(strlen(intal1) + 1));
		strcpy(final,intal1);
		return final;
	}
	if(!intal_compare(intal1,"0"))
	{
		char* final  = (char*)malloc(sizeof(char)*(strlen(intal2) + 1));
		strcpy(final,intal2);
		return final;
	}
	int cmp = intal_compare(intal1,intal2);
	if(cmp == 1)
	{
		char* temp = intal_mod(intal1,intal2);
		char* temp2 = intal_gcd(intal2,temp);
		free(temp);
		return temp2;
	}
	else
	{
		char* temp = intal_mod(intal2,intal1);
		char* temp2 = intal_gcd(intal1,temp);
		free(temp);
		return temp2;
	}
}

char* intal_fibonacci(unsigned int n)
{
	if(n == 0)
	{
        char* final  = (char*)malloc(sizeof(char)*(2));
		final[0] = '0';
		final[1] = '\0';
		return final;
    }
    if(n == 1 || n == 2){
        char* final  = (char*)malloc(sizeof(char)*(2));
		final[0] = '1';
		final[1] = '\0';
		return final;
    }
	char *fib1 = (char*)malloc(sizeof(char)*1001);
    char *fib2 = (char*)malloc(sizeof(char)*1001);
    char *result = (char*)malloc(sizeof(char)*1001);
	fib1[0] = '0';
	fib1[1] = '\0';
	fib2[0] = '1';
	fib2[1] = '\0';
	for(unsigned int i = 2;i <= n;i++)
	{
		char* temp = intal_add(fib1,fib2);
		strcpy(result,temp);
        strcpy(fib1,fib2);
        strcpy(fib2,result);
		free(temp);
    }
    free(fib1);
    free(fib2);
    return result;
}
		

char* intal_factorial(unsigned int n)
{
	
    char* result = (char*)malloc(sizeof(char)*(1001));
    char* num = (char*)malloc(sizeof(char)*(1001));
    if(n == 0)
    {
		free(result);
		free(num);
        char* final = (char*)malloc(sizeof(char)*2);
		final[0] = '1';
		final[1] = '\0';
        return final;
    }

    result[0] = '1';
	result[1] = '\0';
    
    for(int i = 1; i <= n; i++)
    {
		sprintf(num, "%d", i);
		char* temp = result;
        result = intal_multiply(result, num);
		free(temp);
		
    }
	free(num);
    return result;
}

char* intal_bincoeff(unsigned int n, unsigned int k)
{
    if(n == 0 || n < k)
	{
		char* final = (char*)malloc(sizeof(char)*2);
		final[0] = '0';
		final[1] = '\0';
        return final;
	}
        
    if(n == k || k == 0)
	{
        char* final = (char*)malloc(sizeof(char)*2);
		final[0] = '1';
		final[1] = '\0';
        return final;
    }
    if(n - k < k)
	{
        k = n - k;
    }
	
    char** dp_array = (char**)malloc(sizeof(char*)*(k + 1));
    char* result = (char*)malloc(sizeof(char*) * 1001);
    for(unsigned int i = 0;i <= k;i++){
        dp_array[i] = (char*)malloc(sizeof(char*) * 1001);
        strcpy(dp_array[i],"0");
    }   
    strcpy(dp_array[0],"1");
	int min;
    for(unsigned int i = 1; i <= n; i++) 
    {
		if(i < k)
		{
			min = i;
		}
		else
		{
			min = k;
		}
        for(unsigned int j = min; j > 0; j--)
		{
			char* temp = intal_add(dp_array[j],dp_array[j - 1]);
            strcpy(dp_array[j],temp);
			free(temp);
		}
    } 
    strcpy(result,dp_array[k]);
    for(int i = 0;i < k + 1;i++)
	{
		free(dp_array[i]);
	}
	free(dp_array);
    return result;
}

int intal_max(char **arr, int n)
{
	if(n == 0)
	{
		return -1;
	}
	if(n == 1)
	{
		return 0;
	}
	int index = 0;
	
	for(int i = 1;i < n;i++)
	{
		if(intal_compare(arr[i],arr[index]) == 1)
		{
			
			index = i;
		}
	}
	return index;
}

int intal_min(char **arr, int n)
{
	if(n == 0)
	{
		return -1;
	}
	if(n == 1)
	{
		return 0;
	}
	int index = 0;
	
	//char* result = strdup(arr[0]);
	for(int i = 1;i < n;i++)
	{
		if(intal_compare(arr[i],arr[index]) == -1)
		{
			
			index = i;
		}
	}
	return index;
}

int intal_search(char **arr, int n, const char* key)
{
    for(int i = 0;i < n;i++)
	{
        if(intal_compare(key,arr[i]) == 0)
		{
            return i;
        }
    }
    return -1;
}

int intal_binsearch(char **arr, int n, const char* key)
{
	int left = 0;
	int right = n - 1;
    int mid;
	int result = -1;
    while(left <= right)
	{
        mid = left + (right - left) / 2;
        if(intal_compare(arr[mid],key) == 0)
		{
            result = mid;
			right = mid - 1;
        }
        else if(intal_compare(arr[mid],key) == 1)
		{
            right = mid - 1;
        }
        else
		{
            left = mid + 1;
        }
    }
    return result;
}

static void heapify(char **arr, int n, int index) 
{ 
    //char *temp = (char*)malloc(sizeof(char)*1001);
	char* temp;
    int max = index;  
    int left = 2 * index + 1;  
    int right = 2 * index + 2;    
    if (left < n && intal_compare(arr[left],arr[max]) == 1)
	{
        max = left;
	}
    if (right < n && intal_compare(arr[right],arr[max]) == 1) 
	{
        max = right;
	}
    if (max != index) 
    { 
        temp = arr[index];
        arr[index] = arr[max];
        arr[max] = temp; 
        //free(temp);
        heapify(arr, n, max); 
    } 
	//free(temp);
} 


void intal_sort(char **arr, int n)
{
	char *temp;
    for (int i = n / 2 - 1; i >= 0; i--) 
	{
		heapify(arr, n, i);
	}
  
    for (int i = n - 1; i > 0; i--) 
    {
		/*	
        strcpy(temp,arr[i]);
        strcpy(arr[i],arr[0]);
        strcpy(arr[0],temp);
		*/
		
        temp = arr[i];
		arr[i] = arr[0];
        arr[0] = temp;

        heapify(arr, i, 0); 
		
    } 
    //free(temp);
    return;
}


char* coin_row_problem(char **arr, int n)
{
	if(n == 1)
	{
		char* final = strdup(arr[0]);
		return final;
	}
    char *prev_prev = malloc(sizeof(char)*1001);
    char *prev = malloc(sizeof(char)*1001);
    char *result = malloc(sizeof(char)*1001);
    
    strcpy(prev_prev,"0");
    strcpy(prev,arr[0]);
    for(int i = 1;i < n;i++)
	{
        //char *prev_prev_add = (charmalloc(sizeof(char)*1002);
        char* prev_prev_add = intal_add(prev_prev,arr[i]);
        //printf("%p %p \n",prev_prev_add,intal_add(prev_prev,arr[i]));
        if(intal_compare(prev_prev_add,prev) == 1)
		{
            strcpy(result,prev_prev_add);
            
        }
        else
		{
            strcpy(result,prev);
        }
        strcpy(prev_prev,prev);
        strcpy(prev,result);  
        //printf("%p %p %p %p\n",prev_prev,prev,result,prev_prev_add); 
        free(prev_prev_add);
    }
	char* final = (char*)malloc(sizeof(char) * (strlen(result) + 1));
	strcpy(final,result);
	free(result);
    free(prev_prev);
    free(prev);
    return final;


}


	


			
	
	
				
