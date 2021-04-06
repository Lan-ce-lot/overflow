/**
 * Create Or Update User Api
 * @param request {
 *     "id": update user id: int,
 *     "username": the user username: str,
 *     "password": create user password: str,
 *     "name": the user name: str,
 * }
 * @return if create or update success return {
 *     "status": 1,
 *     "message": message: str,
 *     "data": user info: object
 * }
 * @throws MissingServletRequestParameterException when create user
 *      {@code username} or {@code password} is {@literal null}
 */