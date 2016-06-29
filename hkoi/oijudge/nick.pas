program
	noname;
const
	num=4;
var
	inst :array[1..num]of string
	priority:array[1..num]of integer;
	in:text;
	i,j,k : integer;
procedure
	init;
begin
	assign(in,'input');
	reset(in);
	for i := 1 to num do
		readln(in,inst[i]);
	close(in);
end;
procedure
	bb(var a,b :string);
var
	tmp :string;
begin
	tmp := a;
	a:=b;
	b:=tmp;
end;
procedure
	yrspri;
begin
	for i:= 1 to num do
	val(copy(inst[i],length(inst[i]-3),4),pri[i],pri[i]);
end;
{set priority}
procedure
	priority(st:string;var pri:integer);
begin
	case st of 
	'January':pri:=1;
	'Feburary':pri:=2;
	'March':pri:=3;
	'April':pri:=4;
	'May':pri:=5;
	'June':pri:=6;
	'July':pri:=7;
	'August':pri:=8;
	'September':pri:=9;
	'October':pri:=10;
	'November':pri:=11;
	'December':pri:=12;
end;
procedure
	mthpri;
var
	i,j :integer;
	tmp,tmp2:integer;
	primth:array[1..num] of integer
begin
	for i := 1 to num do
		begin
		for j := 1 to length[i] do
			if (ord(copy(in[i],j,1))>64) and (ord(copy(in[i],j,1))<90)
				then tmp:= j
				else if ord(copy(in[i],j,1)) = ','
					then tmp2 := j;
	priority(copy(in[i],tmp,tmp2-tmp),primth[i]);
		end;
end;
begin
	init;
	priority;
	mthpri;
	yrpri;
	for i:= 1 to num do
	pri[i]:=pri[i]+primth[i];{overall priority}
	for j := num downto 1 do
		for k := 1 to j do
			if pri[i]>pri[i+1]
				then bb(in[i],in[i+1]);
	for i := 1 to num do
	Writeln(in[i]);
end.