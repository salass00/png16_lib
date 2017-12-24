#ifndef PNG16_INTERFACE_DEF_H
#define PNG16_INTERFACE_DEF_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif
#ifndef LIBRARIES_PNG16_H
#include <libraries/png16.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct PNG16IFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct PNG16IFace *Self);
	uint32 APICALL (*Release)(struct PNG16IFace *Self);
	void APICALL (*Expunge)(struct PNG16IFace *Self);
	struct Interface * APICALL (*Clone)(struct PNG16IFace *Self);
	/* FIXME: Add libpng16 functions */
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* PNG16_INTERFACE_DEF_H */
