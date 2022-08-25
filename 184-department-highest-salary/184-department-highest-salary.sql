# Write your MySQL query statement below
select d.name as Department , e.name as Employee, e.salary as Salary from department d, employee e
where  d.id= e.departmentid and
e.salary = (select max( salary ) from employee where departmentId =e.departmentid);
