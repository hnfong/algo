program p1044;
type
	bignum = array[1..3000] of longint;
const	log2 =  ln(2)/ln(10);
var
	i,j,k,n,t : longint;
	a, b : bignum;
	c : char;
	l : double;
procedure dump(x : bignum);
var i : longint;
begin
	for i := n+1 downto 1 do begin
		write(x[i]:1);
	end;writeln;
end;

function compare(var a,b:bignum) : longint;
var
	i,j,k : longint;
begin
	for i := n+1 downto 1 do begin
		if a[i]>b[i] then begin compare := 1; exit; end;
		if a[i]<b[i] then begin compare := -1; exit; end;
	end;
	compare := 0;
end;

begin
	n := 0;
	while not eoln do begin
		read(c);
		inc(n);
		a[n] := ord(c)-48;
	end;readln;
	for i := 1 to n div 2 do begin
		t := a[i];
		a[i] := a[n-i+1];
		a[n-i+1] := t;
	end;
	fillchar(b,sizeof(b),0);
	b[1] := 1;{ <--- 2^0 }
	l := 0 ; 
	for i := 1 to 4000 do begin
		for j := 1 to trunc(l)+1 do begin
			b[j] := b[j] * 2;
		end;
		for j := 1 to trunc(l)+1 do begin
			b[j+1]:=b[j+1]+(b[j] div 10);
			b[j] := b[j] mod 10;
		end;
		l := l + log2;
		if (l < n-1) then continue;
		if compare(b,a)>0 then begin
			writeln(i);
			break;
		end;
	end;
end.

