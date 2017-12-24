#ifndef PROTO_PNG16_H
#define PROTO_PNG16_H

/****************************************************************************/

#ifndef __NOLIBBASE__
 extern struct Library * PNG16Base;
#endif

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/png16.h>
 #ifdef __USE_INLINE__
  #include <inline4/png16.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_PNG16_PROTOS_H
  #define CLIB_PNG16_PROTOS_H 1
 #endif /* CLIB_PNG16_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  extern struct PNG16IFace *IPNG16;
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_PNG16_PROTOS_H
  #include <clib/png16_protos.h>
 #endif /* CLIB_PNG16_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/png16.h>
  #else
   #include <ppcinline/png16.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/png16_protos.h>
  #endif /* __PPC__ */
 #else
  #include <pragmas/png16_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_PNG16_H */
