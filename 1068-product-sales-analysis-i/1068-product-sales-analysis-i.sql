# Write your MySQL query statement below
SELECT t.year, t.price, p.product_name
FROM Sales t
LEFT JOIN Product p
ON t.product_id = p.product_ID;
