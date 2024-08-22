SQL 코딩 테스트를 대비하기 위해 알아두면 좋은 SQL 문법과 개념들을 정리해드리겠습니다.

### 1. **기본 SQL 문법**

#### 1.1 **SELECT 문**
- **기본 형태**: 데이터베이스에서 데이터를 조회할 때 사용합니다.
  ```sql
  SELECT column1, column2 
  FROM table_name;
  ```
- **WHERE 절**: 조건을 걸어 데이터를 필터링합니다.
  ```sql
  SELECT column1, column2 
  FROM table_name 
  WHERE condition;
  ```
- **DISTINCT**: 중복된 데이터를 제거하고 고유한 값을 조회합니다.
  ```sql
  SELECT DISTINCT column1 
  FROM table_name;
  ```
- **ORDER BY**: 데이터를 정렬합니다.
  ```sql
  SELECT column1, column2 
  FROM table_name 
  ORDER BY column1 ASC/DESC;
  ```

#### 1.2 **JOIN 문**
- **INNER JOIN**: 두 테이블 간 공통된 부분만 조회합니다.
  ```sql
  SELECT columns 
  FROM table1
  INNER JOIN table2 
  ON table1.column = table2.column;
  ```
- **LEFT JOIN**: 왼쪽 테이블의 모든 데이터와 일치하는 오른쪽 테이블의 데이터를 조회합니다.
  ```sql
  SELECT columns 
  FROM table1
  LEFT JOIN table2 
  ON table1.column = table2.column;
  ```
- **RIGHT JOIN**: 오른쪽 테이블의 모든 데이터와 일치하는 왼쪽 테이블의 데이터를 조회합니다.
  ```sql
  SELECT columns 
  FROM table1
  RIGHT JOIN table2 
  ON table1.column = table2.column;
  ```
- **FULL OUTER JOIN**: 두 테이블의 모든 데이터를 조회하며 일치하는 부분은 병합됩니다.
  ```sql
  SELECT columns 
  FROM table1
  FULL OUTER JOIN table2 
  ON table1.column = table2.column;
  ```

### Self Join의 주요 특징

- **같은 테이블을 두 번 참조**: Self Join을 수행할 때는 동일한 테이블을 두 번 참조하므로, 테이블에 별칭(alias)을 사용하여 구분합니다.
- **일반적인 JOIN과 동일한 방식**: 일반적인 JOIN(예: INNER JOIN, LEFT JOIN)과 동일한 방식으로 동작합니다. 차이점은 동일한 테이블을 참조한다는 점입니다.

### Self Join의 예시

#### 1. **자기 자신과의 관계를 찾기**
부서의 직원 테이블에서 각 직원의 상사(매니저)를 찾는 경우를 예로 들어 보겠습니다. 이때, 직원과 상사 정보가 동일한 테이블에 저장되어 있다고 가정합니다.

```sql
SELECT 
    e.employee_id, 
    e.employee_name, 
    m.employee_name AS manager_name
FROM 
    employees e
INNER JOIN 
    employees m ON e.manager_id = m.employee_id;
```

- 여기서 `employees` 테이블이 두 번 사용됩니다. 하나는 `e`라는 별칭을 사용하고, 다른 하나는 `m`이라는 별칭을 사용합니다.
- `e.manager_id = m.employee_id` 조건을 통해 직원의 매니저를 찾습니다.
- 결과는 각 직원의 ID, 이름, 그리고 그들의 매니저 이름을 포함하게 됩니다.

#### 2. **계층 구조 표현**
자신의 자식 데이터를 찾는 경우에도 Self Join이 사용될 수 있습니다. 예를 들어, 제품 카테고리가 같은 테이블에 부모-자식 관계로 저장되어 있는 경우입니다.

```sql
SELECT 
    c1.category_name AS parent_category, 
    c2.category_name AS child_category
FROM 
    categories c1
LEFT JOIN 
    categories c2 ON c1.category_id = c2.parent_category_id;
```

- 이 예시에서 `categories` 테이블을 두 번 참조하여 부모 카테고리와 자식 카테고리를 찾습니다.
- `c1`은 부모 카테고리를, `c2`는 자식 카테고리를 의미합니다.
- `LEFT JOIN`을 사용하여 모든 부모 카테고리와 그에 해당하는 자식 카테고리를 출력할 수 있습니다.

### Self Join을 사용하는 경우
- **계층 구조**: 예를 들어, 조직도, 카테고리 트리 구조 등에서 부모-자식 관계를 표현할 때.
- **자기 참조 관계**: 테이블의 동일한 데이터가 서로 연결된 경우, 예를 들어 직원과 그 직원의 상사와의 관계.
- **비교 작업**: 동일한 테이블의 서로 다른 행의 데이터를 비교할 때, 예를 들어 같은 테이블의 두 날짜 간의 차이를 비교하는 경우.

Self Join은 동일한 테이블에서 필요한 데이터를 연관시킬 때 매우 유용한 방법이며, 특히 계층적 데이터를 처리하거나 데이터의 관계를 표현할 때 자주 사용됩니다. SQL 코딩 테스트에서도 복잡한 데이터 구조를 다룰 때 유용하게 활용될 수 있습니다.

#### 1.3 **GROUP BY와 집계 함수**
- **GROUP BY**: 데이터를 그룹으로 묶어 집계할 때 사용합니다.
  ```sql
  SELECT column1, COUNT(*) 
  FROM table_name 
  GROUP BY column1;
  ```
- **HAVING 절**: 그룹화된 데이터에 조건을 걸어 필터링합니다.
  ```sql
  SELECT column1, COUNT(*) 
  FROM table_name 
  GROUP BY column1 
  HAVING COUNT(*) > 1;
  ```
- **집계 함수**: SUM, AVG, COUNT, MIN, MAX 등이 있습니다.
  ```sql
  SELECT SUM(column1), AVG(column2) 
  FROM table_name;
  ```

### 2. **고급 SQL 문법**

#### 2.1 **서브쿼리(Subquery)**
- **WHERE 절에서 사용**: 특정 조건에 대한 값을 서브쿼리로 가져옵니다.
  ```sql
  SELECT column1 
  FROM table_name 
  WHERE column2 = (
    SELECT MAX(column2) 
    FROM table_name
    );
  ```
- **FROM 절에서 사용**: 서브쿼리를 테이블처럼 사용합니다.
  ```sql
  SELECT sub.column1 
  FROM (
    SELECT column1 
    FROM table_name) AS sub;
  ```
`IN` 연산자는 SQL에서 특정 값이 여러 값 중 하나와 일치하는지를 확인할 때 사용됩니다. 주로 `WHERE` 절에서 많이 사용되며, 여러 개의 값을 나열하거나 서브쿼리의 결과와 비교할 수 있습니다. 다음은 `IN` 연산자의 사용 예시와 설명입니다.

#### 1. **고정된 값들과의 비교**
- `IN` 연산자를 사용하여 특정 컬럼의 값이 지정된 값들 중 하나와 일치하는지를 확인할 수 있습니다.
  
  ```sql
  SELECT column1, column2 
  FROM table_name 
  WHERE column1 IN ('value1', 'value2', 'value3');
  ```

  이 쿼리는 `column1`의 값이 `'value1'`, `'value2'`, 또는 `'value3'` 중 하나일 경우 해당 레코드를 조회합니다.

#### 2. **서브쿼리와 함께 사용**
- `IN` 연산자는 서브쿼리의 결과를 사용하여 여러 값들과 비교할 수 있습니다.
  
  ```sql
  SELECT column1, column2 
  FROM table_name 
  WHERE column1 IN (SELECT columnX FROM another_table WHERE condition);
  ```

  이 쿼리는 `another_table`에서 특정 조건에 맞는 `columnX`의 값들과 `table_name`의 `column1`을 비교하여 일치하는 레코드를 조회합니다.

#### 3. **NOT IN**
- `NOT IN` 연산자는 `IN`의 반대로, 값이 나열된 목록에 포함되지 않은 경우를 조회할 때 사용됩니다.
  
  ```sql
  SELECT column1, column2 
  FROM table_name 
  WHERE column1 NOT IN ('value1', 'value2', 'value3');
  ```

  이 쿼리는 `column1`의 값이 `'value1'`, `'value2'`, `'value3'` 중 어느 것도 일치하지 않는 레코드를 조회합니다.

#### 4. **NULL을 포함한 IN 사용 시 주의점**
- `IN` 연산자를 사용할 때 서브쿼리나 목록에 `NULL` 값이 포함되면, 예상치 못한 결과가 나올 수 있습니다. 이 경우는 주의가 필요합니다.

  ```sql
  SELECT column1, column2 
  FROM table_name 
  WHERE column1 IN (SELECT columnX FROM another_table WHERE columnY IS NOT NULL);
  ```

  이 쿼리는 `NULL` 값을 제외한 서브쿼리의 결과와 비교합니다.

`IN` 연산자는 `=` 연산자와 달리 하나의 값이 아닌 여러 개의 값과 비교할 때 매우 유용합니다. 특히, `IN`에 서브쿼리를 결합하여 조건을 유연하게 설정할 수 있는 점이 강력한 기능 중 하나입니다. SQL 코딩 테스트에서도 자주 사용되므로 꼭 숙지해두세요.


#### 2.2 **윈도우 함수(Window Function)**
- **ROW_NUMBER()**: 데이터에 순번을 부여합니다.
  ```sql
  SELECT column1, ROW_NUMBER() 
  OVER (ORDER BY column1) AS row_num 
  FROM table_name;
  ```
- **RANK()**: 동일한 값에 동일한 순위를 부여합니다.
  ```sql
  SELECT column1, RANK() 
  OVER (ORDER BY column1) AS rank_num 
  FROM table_name;
  ```
- **PARTITION BY**: 그룹별로 순번을 매길 때 사용합니다.
  ```sql
  SELECT column1, ROW_NUMBER() 
  OVER (PARTITION BY column2 ORDER BY column1) AS row_num 
  FROM table_name;
  ```

### 3. **데이터 조작 언어 (DML)**

#### 3.1 **INSERT**
- 데이터를 테이블에 삽입합니다.
  ```sql
  INSERT INTO table_name (column1, column2) VALUES (value1, value2);
  ```

#### 3.2 **UPDATE**
- 테이블의 데이터를 수정합니다.
  ```sql
  UPDATE table_name SET column1 = value1 WHERE condition;
  ```

#### 3.3 **DELETE**
- 테이블의 데이터를 삭제합니다.
  ```sql
  DELETE FROM table_name WHERE condition;
  ```

### 4. **데이터 정의 언어 (DDL)**

#### 4.1 **CREATE**
- **테이블 생성**:
  ```sql
  CREATE TABLE table_name (
    column1 datatype,
    column2 datatype,
    ...
  );
  ```

#### 4.2 **ALTER**
- **테이블 수정**: 테이블에 새로운 컬럼을 추가하거나 기존 컬럼을 수정합니다.
  ```sql
  ALTER TABLE table_name ADD column_name datatype;
  ALTER TABLE table_name MODIFY column_name datatype;
  ALTER TABLE table_name DROP COLUMN column_name;
  ```

#### 4.3 **DROP**
- **테이블 삭제**:
  ```sql
  DROP TABLE table_name;
  ```

### 5. **트랜잭션 제어 언어 (TCL)**

#### 5.1 **COMMIT**
- 트랜잭션을 완료하고 변경 사항을 저장합니다.
  ```sql
  COMMIT;
  ```

#### 5.2 **ROLLBACK**
- 트랜잭션을 취소하고 변경 사항을 원래 상태로 되돌립니다.
  ```sql
  ROLLBACK;
  ```

#### 5.3 **SAVEPOINT**
- 트랜잭션 내에서 특정 지점을 설정하여 ROLLBACK 지점을 지정합니다.
  ```sql
  SAVEPOINT savepoint_name;
  ROLLBACK TO savepoint_name;
  ```

이 외에도 SQL 코딩 테스트에서는 데이터베이스 최적화와 인덱스 사용, 데이터 정규화와 비정규화, 복잡한 JOIN과 서브쿼리의 조합 등도 고려될 수 있습니다. 실제 문제를 풀면서 이 문법들을 활용해보는 것이 중요합니다.