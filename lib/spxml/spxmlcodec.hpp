/*
 * Copyright 2007 Stephen Liu
 * For license terms, see the file COPYING along with this library.
 */

#ifndef __spxmlcodec_hpp__
#define __spxmlcodec_hpp__

#define	UTF8_ENCODE  	1
#define	GB18030_ENCODE  2
	
class SP_XmlStringBuffer;

class SP_XmlStringCodec {
public:

	static const char * DEFAULT_ENCODING;

	static int decode( const char * encoding,
			const char * encodeValue, SP_XmlStringBuffer * outBuffer );
	static int encode( const char * encoding,
			const char * decodeValue, SP_XmlStringBuffer * outBuffer );
	static int isNameChar( const char * encoding, char c );

private:
	static const char XML_CHARS [];
	static const char * ESC_CHARS [];

	SP_XmlStringCodec();
};

class SP_XmlUtf8Codec {
public:

	// @return convert how many bytes
	static int utf82uni( const unsigned char * utf8, int * ch );

	static void uni2utf8( int ch, SP_XmlStringBuffer * outBuffer );

private:
	SP_XmlUtf8Codec();
};

class SP_XmlGbkCodec {
public:
	static int gbk2uni(const unsigned char *gbk,int *ch);
	static void uni2gbk(int ch,SP_XmlStringBuffer * outBuffer);
private:
	SP_XmlGbkCodec();
};

#endif

