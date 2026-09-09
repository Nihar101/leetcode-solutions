# Write your MySQL query statement below
select patient_id, patient_name,conditions from Patients as p
where p.conditions like ("% DIAB1%") or p.conditions like("DIAB1%")