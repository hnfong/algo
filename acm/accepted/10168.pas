program p10168;
{
	@JUDGE_ID: 20044WC 10168 PASCAL "Intelligent Exhaustion /w Goldbach's Conjecture"
}
var
	a : array[0..6] of longint;
	i,j : longint;
	n : longint;
	q : boolean;

procedure garmmang(x,y,l:longint);
label out;
var
	i,j : longint;
	p : boolean;
begin
	if q then exit;
	{writeln('GARM ', x+y, ' ',  x, ' ',y,' ', l);}
	a[l] := y;
	if x < 0 then goto out;
	if l = 0 then begin
		if x = 0 then begin
			writeln(a[0],' ',a[1],' ',a[2],' ', a[3]);
			q := true;
		end;
		goto out;
	end;
	for i := x downto 2 do begin
		p := true;
		for j := 2 to trunc(sqrt(i)) do begin
			if (i mod j) = 0 then begin p := false; break; end;
		end;
		if p then begin
			garmmang(x-i,i,l-1);
		end;
		if q then break;
	end;
	out:
end;

begin
	fillchar(a,sizeof(a),0);
	while not eof do begin
		readln(n);
		q := false;
		if (n mod 2) = 1 then begin
			garmmang(n-2,2,3);
		end else begin
			garmmang(n,0,4);
		end;
		if q = false then writeln('Impossible.');
	end;
end.
