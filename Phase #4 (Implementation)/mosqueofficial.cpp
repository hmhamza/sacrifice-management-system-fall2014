#include "mosqueofficial.h"

MosqueOfficial::MosqueOfficial()
{
}

 MosqueOfficial::MosqueOfficial( QString N,QString Cn,QString A,QString Co,QString U,QString P ):Person(N,Cn,A,Co,'M'){
    Username=U;
    Password=P;

 }

 QString MosqueOfficial::getUsername(){
     return Username;
 }

 QString MosqueOfficial::getPassword(){
     return Password;
 }

 QString MosqueOfficial::getType(){
     return 'M';
 }

 QString MosqueOfficial::getOfficialType(){
     return 'M';
 }
