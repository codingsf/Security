/*
 * Copyright (c) 2000-2001 Apple Computer, Inc. All Rights Reserved.
 * 
 * The contents of this file constitute Original Code as defined in and are
 * subject to the Apple Public Source License Version 1.2 (the 'License').
 * You may not use this file except in compliance with the License. Please obtain
 * a copy of the License at http://www.apple.com/publicsource and read it before
 * using this file.
 * 
 * This Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS
 * OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES, INCLUDING WITHOUT
 * LIMITATION, ANY WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT. Please see the License for the
 * specific language governing rights and limitations under the License.
 */


//   NOTE: this is a machine generated file--editing not recommended
//
// sm_vdatypes.h - class definitions for ASN.1 module VdaEnhancedTypes
//
//   This file was generated by snacc on Mon Mar 22 21:49:57 1999
//   UBC snacc by Mike Sample
//   A couple of enhancements made by IBM European Networking Center

#ifndef _sm_vdatypes_h_
#define _sm_vdatypes_h_


//------------------------------------------------------------------------------
// class declarations:

class BigIntegerStr;

//------------------------------------------------------------------------------
// class definitions:

/* [UNIVERSAL 2] IMPLICIT OCTET STRING */
class BigIntegerStr: public AsnOcts
{
public:
			BigIntegerStr(): AsnOcts() {}
			BigIntegerStr (const char *str): AsnOcts (str) {}
			BigIntegerStr (const char *str, const size_t len): AsnOcts (str, len) {}
			BigIntegerStr (const AsnOcts &o): AsnOcts (o) {}
  BigIntegerStr		&operator = (const BigIntegerStr &o)	{ ReSet (o); return *this; }
  BigIntegerStr		&operator = (const char *str)	{ ReSet (str); return *this; }
  virtual AsnType	*Clone() const;

  virtual AsnType	*Copy() const;

  AsnLen		BEnc (BUF_TYPE b);
  void			BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);
  int			BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded);
  int			BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded);

};


//------------------------------------------------------------------------------
// externs for value defs

//------------------------------------------------------------------------------

#endif /* conditional include of sm_vdatypes.h */