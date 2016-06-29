program
       noname00;
const
     num=14;
var
   file1:text;
   main:array[1..num] of string;
   pri,mthpri,yrpri,datepri:array[1..num] of longint;
   i,j,k :longint;
procedure
         init;
begin
     assign(file1,'input.txt');
     reset(file1);
     for i := 1 to num do
         readln(file1,main[i]);
     close(file1);
end;
procedure
         term;
	 var i : longint;
begin
for i := 1 to num do
    Writeln(main[i]);
readln;
end;
function mth2(st:string) : longint;
var pri:longint;
begin
	if st='January'then pri:=1;
	if st='Feburary'then pri:=2;
	if st='March'then pri:=3;
	if st='April'then pri:=4;
	if st='May'then pri:=5;
	if st='June'then pri:=6;
	if st='July'then pri:=7;
	if st='August'then pri:=8;
	if st='September'then pri:=9;
	if st='October'then pri:=10;
	if st='November'then pri:=11;
	if st='December'then pri:=12;
	mth2 := pri;
end;

procedure
         yr;
var
   e :longint;
begin
     for i := 1 to num do
         begin
              val(copy(main[i],length(main[i])-3,4),yrpri[i],e);
              yrpri[i]:=yrpri[i]*10000
         end;
end;
procedure
         mth;
var
   j,tmp,tmp2 :longint;
   temp : char;
begin
     for i:= 1 to num do
         begin
         for j:=1 to length(main[i])do
             begin
             if main[i][j]=' '
                then if (main[i][j+1]>='a')and(main[i][j+1]<='z')
                        then main[i][j+1]:=chr(ord(main[i][j+1])-32);
             if (main[i][j]>='A') and (main[i][j]<='Z')
                then tmp:=j
                else if (main[i][j]=',')
                     then tmp2:=j;
     mthpri[i]:= mth2(copy(main[i],tmp,tmp2-tmp));
     mthpri[i]:=mthpri[i]*100;
         end;
     end;
end;
procedure
         finalsort;
procedure
         bbsort(var a,b :string);
var
   tmp:string;
begin
     tmp:=a;
     a:=b;
     b:=tmp;
end;
procedure
         intsort(var a,b:longint);
var
   tmp:longint;
begin
     tmp:=a;
     a:=b;
     b:=tmp;
end;
begin
     for i := num downto 1 do
         for j:= 1 to i-1 do
             begin
                  if pri[j]>pri[j+1]
                     then begin
                               bbsort(main[j],main[j+1]);
                               intsort(pri[j],pri[j+1]);
                          end;
             end;
end;
procedure
         addition;
begin
     for i:= 1 to num do
     pri[i]:=mthpri[i]+yrpri[i]+datepri[i];
end;
procedure
         date;
var
   e:longint;
begin
     for i := 1 to num do
         begin
              if(main[i][2] >='0')and (main[i][2]<='9')
              then val(main[i][1]+main[i][2],datepri[i],e)
              else val(main[i][1],datepri[i],e);
         end;
end;
begin
init;
yr;
mth;
date;
addition;
finalsort;
term;
end.
