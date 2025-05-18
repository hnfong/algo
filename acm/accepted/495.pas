program p495;
{
	@JUDGE_ID: 20044WC 495 PASCAL "HPA"
	
	Optimizations included to make the output roll faster (buffering the output)
}
type hpa = array[1..131] of longint;
var
	i,j,k,c : longint;
	a : array[0..5000] of hpa;
	buf : array[0..1100] of char;
	buflen : longint;
	s : string;

function pad(x:longint):string[8];
var
	i : longint;
	s : string[8];
begin
	s := '';
	for i := 8 downto 1 do begin
		s := chr(x mod 10 + 48) + s;
		x := x div 10;
	end;
	pad := s;
end;

procedure bwrite(s:string);
begin
	move(s[1],buf[buflen],length(s));
	buflen := buflen+length(s);
end;

function i2s(x:longint):string[10]; var s:string[10]; begin str(x,s); i2s := s; end;

begin
	fillchar(a,sizeof(a),0);
	a[1,1] := 1;
	for i := 2 to 5000 do begin
		c := 0;
		for j := 1 to 131 do begin
			a[i,j] := a[i-1,j]+a[i-2,j]+c;
			c := a[i,j] div 100000000;
			a[i,j] := a[i,j] mod 100000000;
		end;
	end;
	while not eof do begin
		readln(k);
		buflen := 0;
		bwrite('The Fibonacci number for '+ i2s(k)+ ' is ');
		for i := 131 downto 1 do begin
			if a[k,i] > 0 then break;
		end;
		str(a[k,i], s);
		bwrite(s);
		dec(i);
		for j := i downto 1 do begin
			bwrite(pad(a[k,j]));
		end;
		buf[buflen] := chr(0);
		writeln(buf);
	end;
end.
