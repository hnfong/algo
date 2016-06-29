program lexical;
var
	i,j,k : longword;
	ac : longword;
	n : longword;
	a : array[0..14] of longword;
function fact(x : longword) : longword;
var i : longword; t : longword;
begin
	t := 1;
	for i := 2 to x do begin
		t := t * i;
	end;
	fact := t;
end;

function lex(x : longword) : longword;
var t : longword; i : longword;
begin
	if x = n then begin lex := 1; exit; end;
	t := a[x];
	for i := x+1 to n do begin
		if a[i] > t then dec(a[i]);
	end;
	lex := fact(n-x)*(t) + lex(x+1);
end;

begin
	{assign(input, 'lexical.in');}
	reset(input);
	{assign(output,'lexical.out');}
	rewrite(output);
	readln(n);
	for i := 1 to n do begin
		read(a[i]);
	end;readln;
	writeln(lex(1));
	close(output);
end.

