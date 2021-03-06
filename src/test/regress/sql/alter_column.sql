set grammar to oracle;
--增加列，3种语法
create table tt(tid int,name varchar(2));
insert into tt values(1, 'a');
alter table tt add(dct1 varchar(10));
alter table tt add dct2 varchar(10);
alter table tt add column dct3 varchar(10);
drop table tt;
--删除单列
create table tt(tid int,name varchar(2));
insert into tt values(1,'a');
insert into tt values(2,'b');
alter table tt drop column name;
drop table tt;
--删除多列
create table tt(tid int,name varchar(2),tel char(10));
alter table tt drop(name,tel);
drop table tt;
--删除分片键列
create table tt(name char(2),tid int);
alter table tt drop column name;
drop table tt;
--修改列
create table tt(tid int,name varchar(2));
alter table tt modify name char(10);
alter table tt modify name default('a');
drop table tt;
create table tt(tid int,name varchar(2),tel char(11));
alter table tt modify(name char(10),tel char(12));
drop table tt;
--重命名列
create table tt(tid int,name varchar(2));
alter table tt rename column name to na;
drop table tt;
