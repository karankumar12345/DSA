SELECT 
    p.project_id,
    ROUND(
        IFNULL(SUM(ep.experience_years) / COUNT(ep.employee_id), 0),
        2
    ) AS average_years
FROM Project p
LEFT JOIN Employee ep 
    ON p.employee_id = ep.employee_id
GROUP BY p.project_id;