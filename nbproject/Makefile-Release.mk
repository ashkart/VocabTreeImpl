#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/src/BowVector.o \
	${OBJECTDIR}/src/Column.o \
	${OBJECTDIR}/src/FBrief.o \
	${OBJECTDIR}/src/FORB.o \
	${OBJECTDIR}/src/FSurf64.o \
	${OBJECTDIR}/src/FeatureVector.o \
	${OBJECTDIR}/src/QueryResults.o \
	${OBJECTDIR}/src/ScoringObject.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../../SDKs/opencv-2.4.13/build/lib -L../../SDKs/DLib-1.0/build

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voctreeimpl

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voctreeimpl: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voctreeimpl ${OBJECTFILES} ${LDLIBSOPTIONS} -lpqxx -lpq

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../SDKs/DLib-1.0/include/DUtils -I../../SDKs/DLib-1.0/include/DUtilsCV -I../../SDKs/DLib-1.0/include/DVision -I../../SDKs/opencv-2.4.13/include/opencv -I../../SDKs/opencv-2.4.13/include/opencv2 -Iinclude/DBoW2 -Iinclude -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/src/BowVector.o: src/BowVector.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../SDKs/DLib-1.0/include/DUtils -I../../SDKs/DLib-1.0/include/DUtilsCV -I../../SDKs/DLib-1.0/include/DVision -I../../SDKs/opencv-2.4.13/include/opencv -I../../SDKs/opencv-2.4.13/include/opencv2 -Iinclude/DBoW2 -Iinclude -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/BowVector.o src/BowVector.cpp

${OBJECTDIR}/src/Column.o: src/Column.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../SDKs/DLib-1.0/include/DUtils -I../../SDKs/DLib-1.0/include/DUtilsCV -I../../SDKs/DLib-1.0/include/DVision -I../../SDKs/opencv-2.4.13/include/opencv -I../../SDKs/opencv-2.4.13/include/opencv2 -Iinclude/DBoW2 -Iinclude -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Column.o src/Column.cpp

${OBJECTDIR}/src/FBrief.o: src/FBrief.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../SDKs/DLib-1.0/include/DUtils -I../../SDKs/DLib-1.0/include/DUtilsCV -I../../SDKs/DLib-1.0/include/DVision -I../../SDKs/opencv-2.4.13/include/opencv -I../../SDKs/opencv-2.4.13/include/opencv2 -Iinclude/DBoW2 -Iinclude -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/FBrief.o src/FBrief.cpp

${OBJECTDIR}/src/FORB.o: src/FORB.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../SDKs/DLib-1.0/include/DUtils -I../../SDKs/DLib-1.0/include/DUtilsCV -I../../SDKs/DLib-1.0/include/DVision -I../../SDKs/opencv-2.4.13/include/opencv -I../../SDKs/opencv-2.4.13/include/opencv2 -Iinclude/DBoW2 -Iinclude -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/FORB.o src/FORB.cpp

${OBJECTDIR}/src/FSurf64.o: src/FSurf64.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../SDKs/DLib-1.0/include/DUtils -I../../SDKs/DLib-1.0/include/DUtilsCV -I../../SDKs/DLib-1.0/include/DVision -I../../SDKs/opencv-2.4.13/include/opencv -I../../SDKs/opencv-2.4.13/include/opencv2 -Iinclude/DBoW2 -Iinclude -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/FSurf64.o src/FSurf64.cpp

${OBJECTDIR}/src/FeatureVector.o: src/FeatureVector.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../SDKs/DLib-1.0/include/DUtils -I../../SDKs/DLib-1.0/include/DUtilsCV -I../../SDKs/DLib-1.0/include/DVision -I../../SDKs/opencv-2.4.13/include/opencv -I../../SDKs/opencv-2.4.13/include/opencv2 -Iinclude/DBoW2 -Iinclude -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/FeatureVector.o src/FeatureVector.cpp

${OBJECTDIR}/src/QueryResults.o: src/QueryResults.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../SDKs/DLib-1.0/include/DUtils -I../../SDKs/DLib-1.0/include/DUtilsCV -I../../SDKs/DLib-1.0/include/DVision -I../../SDKs/opencv-2.4.13/include/opencv -I../../SDKs/opencv-2.4.13/include/opencv2 -Iinclude/DBoW2 -Iinclude -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QueryResults.o src/QueryResults.cpp

${OBJECTDIR}/src/ScoringObject.o: src/ScoringObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../SDKs/DLib-1.0/include/DUtils -I../../SDKs/DLib-1.0/include/DUtilsCV -I../../SDKs/DLib-1.0/include/DVision -I../../SDKs/opencv-2.4.13/include/opencv -I../../SDKs/opencv-2.4.13/include/opencv2 -Iinclude/DBoW2 -Iinclude -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ScoringObject.o src/ScoringObject.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voctreeimpl

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
