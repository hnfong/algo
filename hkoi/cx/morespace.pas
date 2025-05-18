program morespace;
{damn, use jor 2 hours to code this ><}
var
	i,n : longint;
	dp : array[1..10000] of longint;
	bt : array[1..10000] of longint;
	l : array[1..1000] of string[50];
	ll : array[1..1000] of longint;
	s : array[1..10000] of char;
	lens : longint;

function dpmin(off : longint) : longint; { return the num of words with the offset }
var
	i,j,t,mi,b : longint;
	bo : boolean;
begin
	if off = lens+1 then begin dpmin := 0; exit; end; { base case }
	if off > lens then begin dpmin := 10000000; exit; end;
	if dp[off] < 10000000 then begin dpmin := dp[off]; exit; end;

	t := 10001;
	mi := 10001;

	for i := 1 to n do begin
		bo := true;
		for j := 1 to ll[i] do begin
			if off+j-1 > 10000 then begin bo := false; break; end;
			if s[off+j-1] <> l[i][j] then begin bo := false ; break; end;
		end;
		if bo then begin
			t := 1 + dpmin(off+ll[i]);
			if (t < mi)  then begin
				mi := t;
				b := off + ll[i];
			end;
		end;
	end;
	dp[off] := mi;
	if mi < 10001 then bt[off] := b;
	dpmin := mi;
end;

begin
	fillchar(s, sizeof(s), 0);
	fillchar(l, sizeof(l), 0);
	fillchar(bt, sizeof(bt), 0);
	for i := 1 to 10000 do dp[i] := 10000000;
	
	readln(n);
	for i := 1 to n do begin
		readln(l[i]);
		ll[i] := length(l[i]);
	end;
	i := 0;
	while not eoln do begin
		inc(i);
		read(s[i]);
	end;
	
	lens := length(s);
	writeln(dpmin(1));
end.

