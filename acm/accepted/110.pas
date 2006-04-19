program p110;
{
@JUDGE_ID: 20044WC 110 PASCAL "Recursion"
}
var
	i,j,k,n : longint;
	f : longint;
procedure indent(x:longint);var i : longint; begin for i := 1 to x do write('  '); end;

procedure permutate(s:string[8];l:longint);
var t :char; i,j:longint;
begin
	if l = n then begin
		indent(l);
		write('writeln(');
		for j := 1 to n-1 do write(s[j],',');
		write(s[n]);
		writeln(')');
		exit;
	end;

	for i := l downto 1 do begin
		if i = l then indent(l);
		writeln('if ', s[i], ' < ', s[i+1], ' then');
		permutate(s,l+1);
		t := s[i];
		s[i] := s[i+1];
		s[i+1] := t;
		indent(l);
		if i = 1 then writeln('else') else write('else ');
	end;
	permutate(s,l+1);
end;
begin
	readln(f);
	for i := 1 to f do begin
		readln(n);
		readln;
		writeln('program sort(input,output);');
		writeln('var');
		writeln('', copy('a,b,c,d,e,f,g,h', 1, n*2-1), ' : integer;');
		writeln('begin');
		indent(1);
		writeln('readln(', copy('a,b,c,d,e,f,g,h', 1, n*2-1), ');');
		permutate('abcdefgh',1);
		writeln('end.');
		if i < f then writeln;
	end;
end.
