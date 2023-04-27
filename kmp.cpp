
#include <bits/stdc++.h>

void computeLPSArray(char* pat, int M, int* lps);

void KMPSearch(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	int lps[M];

	computeLPSArray(pat, M, lps);

	int i = 0; 
	int j = 0; 
	while ((N - i) >= (M - j)) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			cout << "Found pattern at index %d ", i - j << endl;
			j = lps[j - 1];
		}

		else if (i < N && pat[j] != txt[i]) {
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}

void computeLPSArray(char* pat, int M, int* lps)
{
	int len = 0;

	lps[0] = 0; // lps[0] is always 0

	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else 
		{
			if (len != 0) {
				len = lps[len - 1];

				
			}
			else 
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int main()
{
	char text[], pat[];
    cout<< "Enter the Text : " ;
    cin >> text;
    cout<< "Enter the Pattern : " ;
    cin >> pat;
	KMPSearch(pat, text);
	return 0;
}


// char txt[] = "ABABDABACDABABCABAB";
// char pat[] = "ABABCABAB";