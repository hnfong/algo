program p10394;
{
	Outputs pascal source code which solves acm Q10394.
	(if you are brave you can pipe the output to /usr/bin/mail !!)
}
const
	z = 100000;

	{ IF YOU ARE NOT SIDNEY FONG, PLEASE CHANGE THE FOLLOWING!! }
	id = '20044WC';
	{ OTHERWISE I WILL HATE U TILL DEATH }
var
	i,j,n : longint;
	p1,p2 : boolean;
begin
	i := 3;
	writeln('program p10394;');
	writeln('{ @JUDGE_ID: ',id,' 10394 PASCAL "HC" }');
	writeln('const');
	writeln('	hc : array[1..',z,'] of longint = ');
	writeln('(');
	n := 0;
	while n < z do begin
		p1 := true;
		for j := 2 to trunc(sqrt(i)) do begin
			if (i mod j) = 0 then begin
				p1 := false;
				break;
			end;
		end;
		p2 := true;
		for j := 2 to trunc(sqrt(i+2)) do begin
			if ( (i+2) mod j) = 0 then begin
				p2 := false;
				break;
			end;
		end;
		if (p1) and (p2) then begin
			inc(n);
			if n = z then writeln(i) else writeln(i,',');
		end;
		i := i + 2;
	end;
	writeln(');');
	writeln('var i : longint;');
	writeln('begin');
	writeln('	while not eof do begin');
	writeln('		readln(i);');
	writeln('		writeln(''('',hc[i],'', '',hc[i]+2, '')'');');
	writeln('	end;');
	writeln('end.');
end.
