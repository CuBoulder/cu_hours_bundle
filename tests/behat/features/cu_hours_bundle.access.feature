@cu_hours_bundle
Feature: CU Hours Block Type

    When I login to a Web Express website
    As an authenticated user with the right permission
    I should be able to create an hours block

    Scenario Outline: An authenticated user should be able to access the form for adding an hours block
        Given  I am logged in as a user with the <role> role
        When I go to "admin/content/hours/add"
        Then I should see <message>

        Examples:
            | role            | message         |
            | edit_my_content | "Access Denied" |
            | edit_only       | "Access Denied" |
            | content_editor  | "Create Hours"  |
            | site_owner      | "Create Hours"  |
            | administrator   | "Create Hours"  |
            | developer       | "Create Hours"  |

    Scenario: An anonymous user should not be able to access the form for adding an hours block
        When I am on "admin/content/hours/add"
        Then I should see "Access denied"