/* File: command.h */
#ifndef COMMAND_H
#define COMMAND_H

#include "boolean.h"
#include "string.h"
#include "komponen.h"
#include "player.h"
#include "order.h"

void ADDCOMPONENT(Stack *S, List *L, boolean StartBuild);
/* Memasang komponen pada komputer rakitan player */

void REMOVECOMPONENT(Stack *S, List *L, boolean StartBuild);
/* Mencopot komponen pada komputer rakitan player */

void END_DAY(Queue *Q, ArrNama N, ArrKomponen K);
/* Mengakhiri hari yang berjalan dan menuju keesokan hari */

#endif
