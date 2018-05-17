CREATE or replace procedure check_res(input_id in number, chk out number) as
	temp number;
begin
	select is_res into temp
	from student
	WHERE id = input_id;
	chk:=temp;
end;
/
