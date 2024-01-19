#pragma once
#pragma pack(1)
#ifndef MAX_ENTITIES
#define MAX_ENTITIES 64
#endif
#ifndef MAX_COMPONENTS
#define MAX_COMPONENTS 32
#endif
static unsigned int nextEntity=-1;
static unsigned char Entities[MAX_ENTITIES]={};
#define __QUERY(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_A,_B,...) ((A)|(B)|(C)|(D)|(E)|(F)|(G)|(H)|(I)|(J)|(K)|(L)|(M)|(N)|(O)|(P)|(Q)|(R)|(S)|(T)|(U)|(V)|(W)|(X)|(Y)|(Z)|(a)|(b)|(c)|(d)|(e)|(f)|(g)|(h)|(i)|(j)|(k)|(l)|(m)|(n)|(o)|(p)|(q)|(r)|(s)|(t)|(u)|(v)|(w)|(x)|(y)|(z)|(_0)|(_1)|(_2)|(_3)|(_4)|(_5)|(_6)|(_7)|(_8)|(_9)|(_A)|(_B))
#define Query(...) __QUERY(__VA_ARGS__,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0)
#if MAX_COMPONENTS > 32
static unsigned long long numComponents=1llu;
static unsigned long long EntityComponents[MAX_ENTITIES]={};
#else
static unsigned int numComponents=1u;
static unsigned int EntityComponents[MAX_ENTITIES]={};
#endif
#define newCompStruct(name,...) static unsigned char name;__attribute__((constructor)) void __##name##Setup(void){name=numComponents;numComponents<<=1u;}typedef struct __VA_ARGS__ name##_CompType;static name##_CompType name##_Arr[MAX_ENTITIES]
#define newComp(name,type) static unsigned char name;__attribute__((constructor)) void __##name##Setup(void){name=numComponents;numComponents<<=1u;}typedef type name##_CompType;static name##_CompType name##_Arr[MAX_ENTITIES]
#define newProp(name) static unsigned char name;__attribute__((constructor)) void __##name##Setup(void){name=numComponents;numComponents<<=1u;}
#define newEntity() ++nextEntity;Entities[nextEntity]=1u
#define removeEntity(e) Entities[e]=0u
#define with(name,...) ;EntityComponents[nextEntity]|=name;name##_Arr[nextEntity]=(name##_CompType)__VA_ARGS__
#define is(name) ;EntityComponents[nextEntity]|=name
#define addComp(entity,comp,...) EntityComponents[entity]|=comp;comp##_Arr[entity]=(comp##_CompType)__VA_ARGS__
#define addProp(entity,comp) EntityComponents[entity]|=comp;
#define removeComp(entity,comp) EntityComponents[entity]&=~comp
#define getComp(entity,comp) comp##_Arr[entity]
#define usingComp(comp,name) comp##_CompType name=comp##_Arr[id]
#define usingComp2(comp,name) comp##_CompType name##2=comp##_Arr[id2]
#define usingComp3(comp,name) comp##_CompType name##3=comp##_Arr[id3]
#define usingMutComp(comp,name) comp##_CompType *name=&comp##_Arr[id]
#define usingMutComp2(comp,name) comp##_CompType *name##2=&comp##_Arr[id2]
#define usingMutComp3(comp,name) comp##_CompType *name##3=&comp##_Arr[id3]
#define hasComp(entity,comp) (EntityComponents[entity]&comp)
#define entityHas(entity,...) ((EntityComponents[entity]&Query(__VA_ARGS__))==Query(__VA_ARGS__))
#define Iter(...) unsigned int query=Query(__VA_ARGS__);for(unsigned int id=0;id<nextEntity+1;id++)if(Entities[id]&&((EntityComponents[id]&query)==query))
#define Iter2() for(unsigned int id2=id+1;id2<nextEntity+1;id2++)if(Entities[id2]&&((EntityComponents[id2]&query)==query))
#define Iter3() for(unsigned int id3=id2+1;id3<nextEntity+1;id3++)if(Entities[id3]&&((EntityComponents[id3]&query)==query))
#define UniqIter(...) unsigned int query=Query(__VA_ARGS__);unsigned int id=-1u;for(id=0;id<nextEntity+1;id++)if(Entities[id]&&((EntityComponents[id]&query)==query))break;if(id!=-1u)
#pragma pack()
