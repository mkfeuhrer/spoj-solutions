#include<bits/stdc++.h>
using namespace std;

void knapsack( int wt[], int val[], int W, int N ) 
{
  int K[ N + 1 ][ W + 1 ], mon[ N + 1 ][ W + 1 ];
  int i, j;
  for ( i = 0; i <= N; ++i ) 
  {
    for ( j = 0; j <= W; ++j ) 
    {
      if ( i == 0 || j == 0 ) 
      {
        K[ i ][ j ] = 0;
        mon[ i ][ j ] = 0;
      }
      else if ( wt[ i - 1 ] <= j ) 
      {
        if ( val[ i - 1 ] + K[ i - 1 ][ j - wt[ i - 1 ] ] > K[ i - 1 ][ j ] ) 
        {
          K[ i ][ j ] = val[ i - 1 ] + K[ i - 1 ][ j - wt[ i - 1 ] ];
          mon[ i ][ j ] = wt[ i - 1 ] + mon[ i - 1 ][ j - wt[ i - 1 ] ];
        }
        else 
        {
          K[ i ][ j ] = K[ i - 1 ][ j ];
          mon[ i ][ j ] = mon[ i - 1 ][ j ];
        }
      }
      else 
      {
        K[ i ][ j ] = K[ i - 1 ][ j ];
        mon[ i ][ j ] = mon[ i - 1 ][ j ];
      }
    }
  }
  int m = K[ N ][ W ];
  int min = 100000000;
  for ( i = 1; i <= W; ++i ) 
  {
    if ( K[ N ][ i ] == m ) 
    {
      if ( mon[ N ][ i ] < min ) 
      {
        min = mon[ N ][ i ];
      }
    }
  }
  printf( "%d %d\n", min, K[ N ][ W ] );
}

int main() 
{
  int wt[ 101 ], val[ 101 ];
  int W, N, i;

  while ( 1 ) 
  {
    scanf( "%d%d", &W, &N );
    if ( W == 0 && N == 0 ) break;
    for ( i = 0; i < N; ++i ) {
      scanf( "%d %d", wt + i, val + i );
    }
    if ( W == 0 || N == 0 ) printf( "0 0\n" );
    else
    knapsack( wt, val, W, N );
  }

  return 0;
}