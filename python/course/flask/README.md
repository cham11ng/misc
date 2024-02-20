# flask-app

- micro web framework
- comes with a minimal set of dependencies
- built-in web server
- has a debugger
- uses standard Python logging
- has built-in unit testing
- enables request and response classes
- provides static asset support
- provides dynamic templates
- supports routing: dynamic URLs, HTTP Methods, Redirecting
- enables error handling
- supports sessions
- popular extensions: Flask-SQLAlchemy, Flask-Mail, Flask-Admin and Flask-Uploads
- FLask-CORS, Flask-Migrate, Flask-User, Marshmallow, Celery

## Library vs Framework

| Library                                                                             | Framework                                                                                                                                                                                                                              |
| ----------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Python libraries are like toolkits.                                                 | Frameworks are predefined structures for application development.                                                                                                                                                                      |
| Each library has specific tools to simplify and expedite certain programming tasks. | Using frameworks provides various benefits, including easing the development process, simplifying the debugging process, enabling more functionality with less code, improving database management efficiency, and enforcing security. |
|                                                                                     | Framework enables you to build the complete application while libraries aid with specific functionality.                                                                                                                               |

## Flask vs Django

| Flask                                              | Django                                                 |
| -------------------------------------------------- | ------------------------------------------------------ |
| Minimal lightweight framework                      | Full-stack framework                                   |
| Includes basic dependencies and is extensible      | Includes everything to create a full-stack application |
| Flexible and lets the developer take most decision | Opinionated and makes most decisions                   |

```py
# Generating good secrets.
python -c 'import secrets; print(secrets.token_hex())'
```
