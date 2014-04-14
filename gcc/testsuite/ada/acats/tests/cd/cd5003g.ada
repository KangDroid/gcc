-- CD5003G.ADA

--                             Grant of Unlimited Rights
--
--     Under contracts F33600-87-D-0337, F33600-84-D-0280, MDA903-79-C-0687,
--     F08630-91-C-0015, and DCA100-97-D-0025, the U.S. Government obtained 
--     unlimited rights in the software and documentation contained herein.
--     Unlimited rights are defined in DFAR 252.227-7013(a)(19).  By making 
--     this public release, the Government intends to confer upon all 
--     recipients unlimited rights  equal to those held by the Government.  
--     These rights include rights to use, duplicate, release or disclose the 
--     released technical data and computer software in whole or in part, in 
--     any manner and for any purpose whatsoever, and to have or permit others 
--     to do so.
--
--                                    DISCLAIMER
--
--     ALL MATERIALS OR INFORMATION HEREIN RELEASED, MADE AVAILABLE OR
--     DISCLOSED ARE AS IS.  THE GOVERNMENT MAKES NO EXPRESS OR IMPLIED 
--     WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE 
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--*
-- OBJECTIVE:
--     CHECK THAT A 'WITH' CLAUSE NAMING 'SYSTEM' NEED NOT BE GIVEN
--     FOR A GENERIC PROCEDURE BODY CONTAINING AN ADDRESS CLAUSE
--     AS LONG AS A 'WITH' CLAUSE IS GIVEN FOR THE UNIT CONTAINING
--     THE GENERIC PROCEDURE SPECIFICATION.

-- HISTORY:
--     VCL  09/09/87  CREATED ORIGINAL TEST.
--     PWB 05/11/89  CHANGED EXTENSION FROM '.DEP' TO '.ADA'.

WITH SYSTEM;
PACKAGE CD5003G_PACK2 IS
     GENERIC
     PROCEDURE CD5003G_PROC2;
END CD5003G_PACK2;

WITH SPPRT13;
WITH REPORT; USE REPORT;
PRAGMA ELABORATE (SPPRT13);
PRAGMA ELABORATE (REPORT);
PACKAGE BODY CD5003G_PACK2 IS
     PROCEDURE CD5003G_PROC2 IS
          TYPE FIXD IS DELTA 0.1 RANGE -10.0 .. 10.0;

          TEST_VAR : FIXD := 0.0;
          FOR TEST_VAR USE AT SPPRT13.VARIABLE_ADDRESS;
          USE SYSTEM;

          FUNCTION IDENT_FIXD (P : FIXD) RETURN FIXD IS
          BEGIN
               IF EQUAL (3, 3) THEN
                    RETURN P;
               ELSE
                    RETURN 0.0;
               END IF;
          END IDENT_FIXD;
     BEGIN
          TEST ("CD5003G", "A 'WITH' CLAUSE NAMING 'SYSTEM' NEED NOT " &
                           "BE GIVEN FOR A GENERIC PROCEDURE BODY " &
                           "CONTAINING AN ADDRESS CLAUSE AS LONG AS " &
                           "A 'WITH' CLAUSE IS GIVEN FOR THE UNIT " &
                           "CONTAINING THE GENERIC PROCEDURE " &
                           "SPECIFICATION");

          TEST_VAR := IDENT_FIXD (3.3);

          IF TEST_VAR /= 3.3 THEN
               FAILED ("INCORRECT VALUE FOR TEST_VAR");
          END IF;

          IF TEST_VAR'ADDRESS /= SPPRT13.VARIABLE_ADDRESS THEN
               FAILED ("INCORRECT ADDRESS FOR TEST_VAR");
          END IF;

         RESULT;
     END CD5003G_PROC2;
END CD5003G_PACK2;


WITH CD5003G_PACK2; USE CD5003G_PACK2;
PROCEDURE CD5003G IS
     PROCEDURE PROC3 IS NEW CD5003G_PROC2;
BEGIN
     PROC3;
END CD5003G;
