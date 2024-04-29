# Hangman  - UNSTPB - ACS | IS - 1AC, 2024
 Proiect de gamification de tipul HANGMAN cu termeni din domeniul economiei circulare, sustenabile

## ROADMAP:
DEADLINE: 7 / 8 MAI - prima versiune | 13 MAI - varianta finala

DISCUTII PE DISCORD: 29 / 30 APRILIE | 3 MAI | 7 / 8 MAI - ULTIMA IN FORMULA COMPLETA

FIZIC: 13 MAI - IN FORMULA COMPLETA

 
## DETALII DE UPLOAD:
A) Se copiaza / cloneaza repository-ul local: git clone https://github.com/andrewen11/Hangman.git

B) Se face verificarea sa fiti pozitionati pe branch-ul PATCH1-DEMO (adica asta: andrewen11-patch1-DEMO), NU e cel de MAIN!!!

C) Fisierele create se incarca in FOLDERELE mentionate in sectiunea "CERINTE": git add NUME_FISIER

D) Confirmati adaugarile cu un mesaj sugestiv de incarcare / actualizare a datelor - git commit -m "MESAJ SUGESTIV"

E) Salvati modificarile din branch: git push origin andrewen11-patch1-DEMO

F) Merge / pull request la final, cand toate fisierele sunt actualizate si sunt conforme

--------------------------------------------------------------------------------------------------------------------------------

## SARCINI DE LUCRU ##

### 1. FISIERE - COORDONATOR: IONESCU RAUL

### DESCRIERE:
Aici vor fi adaugate cele doua tipuri de fisiere:

PRIMUL FISIER - de tip "csv" cu mai multe coloane de forma: intrebari, (raspuns) A, (raspuns) B, (raspuns) C, variante corecte; vor fi de folos cand jucatorul ramane fara vieti si nu vrea sa piarda 

AL DOILEA FISIER - de tip "txt", cu expresii/ cuvinte, fiecare pe cate un rand; acestea vor fi cheia jocului propriu-zis.

### CERINTE: 
a) 20 de intrebari cu variante multiple de raspuns (fisier csv) - se importa cele 6 - 7 din QUIZ 3 (a se vedea link-ul de mai jos) si se mai adauga alte intrebari din prezentare (a se vedea link-ul: Modulul 3)

b) +150 cuvinte pentru fisierul txt (pot sa fie si expresii din 2 - 3 - 4 cuvinte), fiecare expresie/ cuvant pe un anumit rand pentru usurarea procesului de citire - NU SE FOLOSESC DELIMITATORI!

c) FIsierele se incarca in folder-ul de fisiere din branch-ul patch1-DEMO, adica aici: https://github.com/andrewen11/Hangman/blob/andrewen11-patch1-DEMO/FISIERE

### MODEL FISIER .CSV:
Intrebare, A, B, C, Raspuns corect

Ce este economia circulara?, raspuns_A, raspuns_B, raspuns_C, raspuns_D, A & B

Pe ce aspecte se bazeaza?, raspuns_a, raspuns_B, raspuns_C, raspuns_D, C

.....

//COMENTARIU: A, B, C sunt variantele de raspuns. Asa cum apare si pe quiz, pot fi una sau doua / mai multe variante de raspuns




### LINK-URI UTILE:
 A) MODULUL 3 - PREZENTARE ECONOMIE CIRCULARA: https://www.dropbox.com/scl/fo/e8aodnddmstgcel8c6vgo/AJoQhytuykyyeyAxD62S4lk/Tema_3?dl=0&preview=MODULE+3+INDUSTRIAL+STRATEGY+FOR+CIRCULAR+ECONOMY.docx&rlkey=cb6mfnij34lv5mxg5jc9ng5c0&subfolder_nav_tracking=1

 B) QUIZ 3 - INTREBARI: https://www.dropbox.com/scl/fo/e8aodnddmstgcel8c6vgo/AJoQhytuykyyeyAxD62S4lk/Tema_3?dl=0&preview=Quiz+Module+3.docx&rlkey=cb6mfnij34lv5mxg5jc9ng5c0&subfolder_nav_tracking=1

 ### DEADLINE: 30 APRILIE

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

### 2. GRAPHICS - COORDONATORI: CÎRCIOROABĂ RADU, LICAN ȘTEFAN & PLEȘEANU CRISTIAN

### DESCRIERE:
Aici vor fi adaugate fisierele pentru grafica / UI (fisiere png/ jpeg pentru artstyle) si fisiere de configurare / integrare module C - Python

PRIMA CATEGORIE - de tip "jpeg" - implica fisierele pentru artsyle, design, UI (prototip) pentru implementarea propriu-zisa - responsabil: RADU CÎRCIOROABĂ

A DOILEA CATEGORIE - in python, folosind modulele de integrare C - Python, fisier(e) de configurare a graficii si de legatura cu codul din C - responsabili principali: ȘTEFAN LICAN, CRISTIAN PLEȘEANU | secundar: RADU CÎRCIOROABĂ

### CERINTE: 
a) Implementare functii / module / API-uri pentru legarea codului-sursa de grafica

b) GRAFICA - setata pentru o dimensiune fixa (fereastra), include pagina de inceput (titlu, new game, etc) si o alta pagina cu interfata jocului propriu zisa plus altele adiacente: cand jucatorul pierde, apar intrebarile pentru o noua (SI SINGURA) viata + camp pentru tastare litera/litere pt raspunsuri corecte, respectiv cand jucatorul ghiceste cuvantul

c) FIsierele se incarca in folder-ul de "graphics" din branch-ul patch1-DEMO, adica aici: https://github.com/andrewen11/Hangman/blob/andrewen11-patch1-DEMO/GRAPHICS

### a se tine cont ca in fereastra de intrebari sa se permita mai multe raspunsuri corecte - vezi mai jos:

Intrebare, A, B, C, Raspuns corect

Ce este economia circulara?, raspuns_A, raspuns_B, raspuns_C, raspuns_D, A & B

Pe ce aspecte se bazeaza?, raspuns_a, raspuns_B, raspuns_C, raspuns_D, C

.....

//COMENTARIU: A, B, C sunt variantele de raspuns. Asa cum apare si pe quiz, pot fi una sau doua / mai multe variante de raspuns


### LINK-URI UTILE:
 A) DOCUMENTARE TKINTER: https://docs.python.org/3/library/tkinter.html

 B) EXEMPLU JOC HANGMAN CU TKINTER, GITHUB: https://github.com/codebiet/Hangman

 C) GUI - FUNCTII / MODULE PYTHON: https://www.youtube.com/watch?v=iM3kjbbKHQU (IMPORTANT) :)

 D) EXEMPLU PAS CU PAS CODARE - HANGMAN CU TKINTER: https://www.youtube.com/watch?v=CrE1lBMABpY

 E) DOCUMENTARE CTYPES: https://docs.python.org/3/library/ctypes.html

 F) DOCUMENTARE MULTIPROCESSING / API-URI: https://docs.python.org/3/library/multiprocessing.html

 ### DEADLINE: GRAFICA - 2 MAI | PRIMA VERSIUNE - 7 MAI | VERSIUNEA 1 CU EFECTE AUDIO: 8 MAI
 
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

### 3. CODUL SURSĂ - COORDONATORI: BĂLĂLĂU ANDREI & ȘIPANU EDUARD

### DESCRIERE:
Aici va fi adaugat fisierul pentru codul sursa, continand functionalitatile de baza precum citirea datelor din fisier, prelucrarea acestora si managementul cu LISTE SIMPLU INLANTUITE

PRIMA PARTE - implica manipularea lucrului cu fisiere (preluarea datelor, stocarea acestora in functie de alegerea random a intrebarii / cuvantului pentru Hangman)

A DOUA PARTE - presupune lucrul cu liste simplu inlantuite si alte (eventuale( structuri de date ALOCATE DINAMIC pentru eficientizare si simularea mecanismelor "din spatele jocului" - parcurgere, identificare litere, functii de push si pop din lista de litere a cuvantului respectiv, etc.

A TREIA PARTE - DUPA REALIZAREA DEMO-ULUI!!! - integrarea unor module / biblioteci (testare) pentru continut - audio, efecte, focusare pe integrare module

### CERINTE IMPORTANTE, SUPLIMENTARE: 

** Fisierul/ fisierele se incarca in folder-ul de "code" din branch-ul patch1-DEMO, adica aici: https://github.com/andrewen11/Hangman/blob/andrewen11-patch1-DEMO/CODE

** Sa se foloseasca nume de variabile sugestive si complete!

** FARA VARIABILE GLOBALE

### SA SE TINA CONT DE FORMATELE FISIERELOR - exemplu structura fisier csv - vezi mai jos:

Intrebare, A, B, C, Raspuns corect

Ce este economia circulara?, raspuns_A, raspuns_B, raspuns_C, raspuns_D, A & B

Pe ce aspecte se bazeaza?, raspuns_a, raspuns_B, raspuns_C, raspuns_D, C

.....

//COMENTARIU: A, B, C sunt variantele de raspuns. Asa cum apare si pe quiz, pot fi una sau doua / mai multe variante de raspuns. La prima intrebare, se manipuleaza A si B ca fiind raspunsuri corecte, in timp ce pentru a doua intrebare se ia in calcul DOAR raspunsul C, cel corect. Trebuie urmarita sectiunea Raspuns_corect cu mare atentie.


### LINK-URI UTILE:
 A) EXEMPLE IMPLEMENTARI - (1) GITHUB: https://gist.github.com/saroj22322/aa2f0849f33736395544c2d341ab3722 | (2) STACK EXCHANGE: https://codereview.stackexchange.com/questions/217820/beginning-c-hangman

 B) DEFINIRE DE BIBLIOTECI SI ASPECTE CUSTOM CU FUNCTII: https://www.youtube.com/watch?v=90p-9Ha3CJA

 C) *PENTRU INTEGRARE AUDIO & MISCELLANEOUS: https://www.youtube.com/watch?v=iM3kjbbKHQU

 ### DEADLINE: DEMO COD PROPRIU-ZIS: 3 MAI | DEMO COD + MODULE + INTEGRARE CORESPUNZATOARE: 7 MAI
