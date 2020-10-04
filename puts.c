/*	APRS Tracker
 *	Copyright (c) 2020 by SECKC Software
 *
 *	This program monitors GPS and the weather and
 *	transmits reports over APRS over AX.25
 */

#include <stdio.h>
#include <stdio2.h>

/*We use a custom puts, because the default appends a newline*/
int puts( const char * s )
{
while( *s )
	{
	putchar( *s );
	s++;
	}
return 0;
}

/*put a string formatted from a uint8*/
int puts_int_u8( unsigned char i )
{
if( i >= 200 )
	{
	putchar( '2' );
	i -= 200;
	}
else if( i >= 100 )
	{
	putchar( '1' );
	i -= 100;
	}

if( i >= 10 )
	{
	unsigned char m = (i / 10);
	putchar( '0' + m );
	i -= 10 * m;
	}
return 0;
}

/*put a hex string formatted from a uint4*/
int puts_hex_u4( unsigned char i )
{
if( i > 9 )
	{
    putchar( 'A' + i - 10 );
	}
else
	{
	putchar( '0' + i );
	}
return 0;
}

/*put a hex string formatted from a uint8*/
int puts_hex_u8( unsigned char i )
{
puts_hex_u4( i >> 4 );
puts_hex_u4( i & 0xF );
return 0;
}
