program p523;
{
	@JUDGE_ID:  20044WC 523 PASCAL "Warshall..."
}
var
	a,b : longint;
	i,j,k : longint;
	n : longint;
	mn, mi : longint;
	w : array[1..1000,1..1000] of longint;
	tax : array[1..1000] of longint;
	bt : array[1..1000,1..1000] of longint;
procedure back(a,b:longint);
begin
	if a = 0 then exit;
	if b = 0 then begin write(a, '-->'); exit; end;
	back(a,bt[a,b]);
	back(bt[a,b],b);
end;
begin
	readln(mn);
	for mi := 1 to mn do begin { start really doing }
	readln;
	fillchar(w,sizeof(w),0);
	fillchar(bt,sizeof(bt),0);
	n := 0;
	i := 0;
	{ get table }
	while not eoln do begin { < - find n }
		inc(i);
		read(w[1,i]);
		if w[1,i] = -1 then w[1,i] := 1000000000;
	end;readln;
	n := i; { end of find n }
	for i := 2 to n do begin
		for j := 1 to n do begin
			read(w[i,j]);
			if w[i,j] = -1 then w[i,j] := 1000000000;
		end;readln;
	end;
	for i := 1 to n do read(tax[i]); readln;
	{ end get table }

	{ floyd }
	for k := 1 to n do begin
		for i := 1 to n do begin
			for j := 1 to n do begin
				{if (w[i,k] = -1) or (w[k,j] = -1) then continue;}
				if w[i,k]+w[k,j]+tax[k] < w[i,j] then begin
					w[i,j] := w[i,k]+w[k,j]+tax[k];
					bt[i,j] := k;
				end;
			end;
		end;
	end;
	while true do begin
		readln(a,b);
		writeln('From ', a,' to ',b,' :');
		write('Path: ');
		back(a,b);
		writeln(b);
		writeln('Total cost: ',w[a,b]);
		if eoln then begin break;end;
		writeln;
	end;
	if mi < mn then writeln;
	{ end really doing} end;
end.

